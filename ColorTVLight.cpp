/*
 * ColorTVLight.cpp
 *
 *  Created on: 08.05.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "ColorTVLight.h"

ColorTVLight::ColorTVLight(uint8_t index, uint8_t soundPin) : HueMapLight(index) {
	this->soundPin = soundPin;

	setOnCycles(25, 75);
	setOffCycles(25, 75);
	setNoPauseCycles(1000, 2000);
	setPauseCycles(50, 150);

	//setLightFuntion(defaultLightFunction);
	setSoundFuntion(defaultSoundFunction);
}

ColorTVLight::~ColorTVLight() {
}

void ColorTVLight::setup() {

	//if (this->huemap == nullptr) {
		uint8_t huemap[] = {0, 0, 0, 1, 0, 2, 0, 4, 1, 5, 2, 3, 5, 4, 6, 3, 10, 7, 28, 59, 33, 13, 32, 24, 46, 89, 73, 68, 55, 85, 80, 94, 86, 100, 44, 46, 34, 15, 13, 9, 5, 5, 7, 8, 3, 4, 1, 1, 3, 1, 1, 1, 0, 1, 2, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 3, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 2, 3, 3, 6, 3, 2, 10, 7, 3, 3, 18, 18, 10, 12, 12, 15, 9, 3, 7, 4, 7, 10, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		setHueMap(huemap);
	//}
}

void ColorTVLight::defaultSoundFunction(const FlickeringLight*, const LightState, const bool changed) {

}
