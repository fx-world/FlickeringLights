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

	setOnCycles(25, 75);
	setOffCycles(25, 75);
	setNoPauseCycles(1000, 2000);
	setPauseCycles(50, 150);
}

TVLight::~TVLight() {
}

void TVLight::setup() {
	pinMode(pin, OUTPUT);
}

void TVLight::updateState(LightState state) {
	switch (state) {
		case on:
			analogWrite(pin, random(onBrightnessMax - onBrightnessMin) + onBrightnessMin);
			break;

		case off:
			analogWrite(pin, random(offBrightnessMax - offBrightnessMin) + offBrightnessMin);
			break;

		case paused:
			analogWrite(pin, random(pauseBrightnessMax - pauseBrightnessMin) + pauseBrightnessMin);
			break;

		case disabled:
			analogWrite(pin, 0);
			break;
	}
}

void TVLight::setOnBrightness(unsigned int min, unsigned int max) {
	onBrightnessMin = min;
	onBrightnessMax = max;
}

void TVLight::setOffBrightness(unsigned int min, unsigned int max) {
	offBrightnessMin = min;
	offBrightnessMax = max;
}

void TVLight::setPauseBrightness(unsigned int min, unsigned int max) {
	pauseBrightnessMin = min;
	pauseBrightnessMax = max;
}
