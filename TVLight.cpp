/*
 * TVLight.cpp
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "TVLight.h"

TVLight::TVLight(uint8_t pin) {
	this->pin = pin;

	setOnCycles(25, 50);
	setOffCycles(25, 50);
	setNoPauseCycles(1000, 2000);
	setPauseCycles(50, 100);
}

TVLight::~TVLight() {
	// TODO Auto-generated destructor stub
}

void TVLight::setup() {
	pinMode(pin, OUTPUT);
}

void TVLight::updateState(bool state, bool pause) {
	if (!pause) {
		if (state) {
			analogWrite(pin, 255);
			//digitalWrite(pin, state);
		} else {
			analogWrite(pin, 100);
			//digitalWrite(pin, state);
		}

	} else {
		analogWrite(pin, 50);
	}
}
