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

WelderLight::WelderLight(uint8_t pin, uint8_t soundPin) {
	this->pin      = pin;
	this->soundPin = soundPin;

	setOnCycles(1, 5);
	setOffCycles(1, 5);
	setNoPauseCycles(10, 200);
	setPauseCycles(10, 200);

	setLightFuntion(&defaultLightFunction);
	setSoundFuntion(&defaultSoundFunction);
}

WelderLight::~WelderLight() {

}

void WelderLight::setup() {
	pinMode(pin, OUTPUT);
}

void WelderLight::defaultLightFunction(const FlickeringLight* light, const LightState state) {
	WelderLight* weldingLight = (WelderLight*) light;
	switch (state) {
		case on:
			digitalWrite(weldingLight->pin, true);
			break;

		case off:
			digitalWrite(weldingLight->pin, false);
			break;

		case paused:
			digitalWrite(weldingLight->pin, 0);
			break;

		case disabled:
			digitalWrite(weldingLight->pin, 0);
			break;
	}
}

void WelderLight::defaultSoundFunction(const FlickeringLight* light, const LightState state) {
	WelderLight* weldingLight = (WelderLight*) light;
	if (weldingLight->soundPin > 0) {
		switch (state) {
			case on:
				tone(weldingLight->soundPin, random(weldingLight->soundMax - weldingLight->soundMin) + weldingLight->soundMin);
				break;

			case off:
				noTone(weldingLight->soundPin);
				break;

			case paused:
				noTone(weldingLight->soundPin);
				break;

			case disabled:
				noTone(weldingLight->soundPin);
				break;
		}
	}
}

void WelderLight::setSound(int min, int max) {
	soundMin = min;
	soundMax = max;
}
