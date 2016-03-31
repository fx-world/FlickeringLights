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

void WelderLight::updateState(LightState state) {
	switch (state) {
		case on:
			digitalWrite(pin, state);
			if (soundPin > 0) {
				tone(soundPin, random(soundMax - soundMin) + soundMin);
			}
			break;

		case off:
			digitalWrite(pin, state);
			if (soundPin > 0) {
				noTone(soundPin);
			}
			break;

		case paused:
			digitalWrite(pin, 0);
			if (soundPin > 0) {
				noTone(soundPin);
			}
			break;

		case disabled:
			digitalWrite(pin, 0);
			if (soundPin > 0) {
				noTone(soundPin);
			}
			break;
	}
}

void WelderLight::setSound(int min, int max) {
	soundMin = min;
	soundMax = max;
}
