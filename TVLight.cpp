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

	setLightFuntion(defaultLightFunction);
	setSoundFuntion(defaultSoundFunction);
}

TVLight::~TVLight() {
}

void TVLight::setup() {
	pinMode(pin, OUTPUT);
}

void TVLight::defaultLightFunction(const FlickeringLight* light, const LightState state) {
	TVLight* tvLight = (TVLight*) light;
	switch (state) {
		case on:
			analogWrite(tvLight->pin, random(tvLight->onBrightnessMax - tvLight->onBrightnessMin) + tvLight->onBrightnessMin);
			break;

		case off:
			analogWrite(tvLight->pin, random(tvLight->offBrightnessMax - tvLight->offBrightnessMin) + tvLight->offBrightnessMin);
			break;

		case paused:
			analogWrite(tvLight->pin, random(tvLight->pauseBrightnessMax - tvLight->pauseBrightnessMin) + tvLight->pauseBrightnessMin);
			break;

		case disabled:
			analogWrite(tvLight->pin, 0);
			break;
	}
}

void TVLight::defaultSoundFunction(const FlickeringLight* light, const LightState state) {
	TVLight* tvLight = (TVLight*) light;

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
