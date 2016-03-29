/*
 * WelderLight.cpp
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "WelderLight.h"

WelderLight::WelderLight(uint8_t pin) {
	this->pin = pin;
}

WelderLight::WelderLight(uint8_t pin, uint8_t soundPin) {
	this->pin      = pin;
	this->soundPin = soundPin;

	setOnCycles(1, 5);
	setOffCycles(1, 5);
	setNoPauseCycles(10, 200);
	setPauseCycles(10, 200);
}

WelderLight::~WelderLight() {

}

void WelderLight::setup() {
	pinMode(pin, OUTPUT);
}

void WelderLight::updateState(bool state, bool pause) {
	if (!pause) {
		digitalWrite(pin, state);

		if (soundPin > 0) {
			if (state) {
				tone(soundPin, random(soundMax - soundMin) + soundMin);
			} else {
				noTone(soundPin);
			}
		}
	} else {
		digitalWrite(pin, 0);

		if (soundPin > 0) {
			noTone(soundPin);
		}
	}
}

void WelderLight::setSound(int min, int max) {
	soundMin = min;
	soundMax = max;
}
