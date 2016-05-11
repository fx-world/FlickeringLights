/*
 * HueMapLight.cpp
 *
 *  Created on: 26.04.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include "HueMapLight.h"

HueMapLight::HueMapLight(uint8_t index) {
	this->index  = index;
	this->huesum = 0;

	setOnCycles(25, 75);
	setOffCycles(25, 75);
	setNoPauseCycles(1000, 2000);
	setPauseCycles(50, 150);

	setOnLightness(45, 55);
	setOffLightness(20, 45);
	setPauseLightness(0, 20);

	setOnSaturation(75, 100);
	setOffSaturation(75, 100);
	setPauseSaturation(75, 100);

	//setLightFuntion(defaultLightFunction);
}

HueMapLight::~HueMapLight() {

}

void HueMapLight::setHueMap(uint8_t huemap[]) {
	unsigned int huemapSize = sizeof(*huemap) / sizeof(uint8_t);

	if (huemapSize > 360) {
		huemapSize = 360;
	}

	Serial.print(" huemapSize=");
	Serial.print(huemapSize);

	huemapSize = 360;

//	this->huemap = huemap;
	this->huesum = 0;

	for (int i = 0; i < huemapSize; i++) {
		this->huemap[i] = huemap[i];
		this->huesum   += huemap[i];
	}
}

unsigned int HueMapLight::getNextHue() {
	unsigned int result = 0;

	if (shiftingMode && (lastHue != -1)) {
		int shiftMax = (int) (huesum * shiftPercent);
		int shift    = random(shiftMax) - (shiftMax / 2);
		int hue      = lastHue;

		while (abs(shift) > huemap[hue]) {
			if (shift > 0) {
				hue++;
				if (hue >= 360) {
					hue = 0;
				}
				shift -= huemap[hue];
			} else {
				hue--;
				if (hue < 0) {
					hue = 359;
				}
				shift += huemap[hue];
			}
		}
		result = hue;

	} else {
		unsigned int rand   = random(huesum);

		for (int i = 0; i < 360; i++) {
			if (rand <= huemap[i]) {
				result = i;
				break;
			} else {
				rand = rand - huemap[i];
			}
		}
	}

	lastHue = result;

	return result;
}

LightColor HueMapLight::getNextColor(const LightState state) {
	LightColor result;
	uint8_t    hue        = getNextHue();
	uint8_t    saturation;
	uint8_t    lightness;

	switch (state) {
		case on:
			saturation = random(onSaturationMax - onSaturationMin) + onSaturationMin;
			lightness  = random(onLightnessMax - onLightnessMin) + onLightnessMin;
			break;

		case off:
			saturation = random(offSaturationMax - offSaturationMin) + offSaturationMin;
			lightness  = random(offLightnessMax - offLightnessMin) + offLightnessMin;
			break;

		case paused:
			saturation = random(pauseSaturationMax - pauseSaturationMin) + pauseSaturationMin;
			lightness  = random(pauseLightnessMax - pauseLightnessMin) + pauseLightnessMin;
			break;

		case disabled:
			saturation = 0;
			lightness  = 0;
			break;
	}

	result = convertToColor(hue, saturation, lightness);

	return result;
}

LightColor HueMapLight::convertToColor(uint8_t hue, uint8_t saturation, uint8_t lightness) {
	float l = (float) lightness / 100.0f;
	float s = (float) saturation / 100.0f;

	float c = (1 - abs(2*l - 1)) * s;
	float x = c * (1 - abs((hue/60) % 2 - 1));
	float m = l - c/2;

	float r = 0;
	float g = 0;
	float b = 0;

	if ((0 <= hue) && (hue < 60)) {
		r = c;
		g = x;
		b = 0;
	} else if ((60 <= hue) && (hue < 120)) {
		r = x;
		g = c;
		b = 0;
	} else if ((120 <= hue) && (hue < 180)) {
		r = 0;
		g = c;
		b = x;
	} else if ((180 <= hue) && (hue < 240)) {
		r = 0;
		g = x;
		b = c;
	} else if ((240 <= hue) && (hue < 300)) {
		r = x;
		g = 0;
		b = c;
	} else if ((300 <= hue) && (hue < 360)) {
		r = c;
		g = 0;
		b = x;
	}

	r = (r + m) * 255;
	g = (g + m) * 255;
	b = (b + m) * 255;

	return LightColor(r,g,b);
}

void HueMapLight::setOnLightness(unsigned int min, unsigned int max) {
	this->onLightnessMin = min;
	this->onLightnessMax = max;
}

unsigned int HueMapLight::getOnLightnessMin() const {
	return onLightnessMin;
}

unsigned int HueMapLight::getOnLightnessMax() const {
	return onLightnessMax;
}


void HueMapLight::setOffLightness(unsigned int min, unsigned int max) {
	this->offLightnessMin = min;
	this->offLightnessMax = max;
}

unsigned int HueMapLight::getOffLightnessMin() const {
	return offLightnessMin;
}

unsigned int HueMapLight::getOffLightnessMax() const {
	return offLightnessMax;
}


void HueMapLight::setPauseLightness(unsigned int min, unsigned int max) {
	this->pauseLightnessMin = min;
	this->pauseLightnessMax = max;
}

unsigned int HueMapLight::getPauseLightnessMin() const {
	return pauseLightnessMin;
}

unsigned int HueMapLight::getPauseLightnessMax() const {
	return pauseLightnessMax;
}


void HueMapLight::setOnSaturation(unsigned int min, unsigned int max) {
	this->onSaturationMin = min;
	this->onSaturationMax = max;
}

unsigned int HueMapLight::getOnSaturationMin() const {
	return onSaturationMin;
}

unsigned int HueMapLight::getOnSaturationMax() const {
	return onSaturationMax;
}


void HueMapLight::setOffSaturation(unsigned int min, unsigned int max) {
	this->offSaturationMax = max;
	this->offSaturationMin = min;
}

unsigned int HueMapLight::getOffSaturationMin() const {
	return offSaturationMin;
}

unsigned int HueMapLight::getOffSaturationMax() const {
	return offSaturationMax;
}


void HueMapLight::setPauseSaturation(unsigned int min, unsigned int max) {
	this->pauseSaturationMin = min;
	this->pauseSaturationMax = max;
}

unsigned int HueMapLight::getPauseSaturationMin() const {
	return pauseSaturationMin;
}

unsigned int HueMapLight::getPauseSaturationMax() const {
	return pauseSaturationMax;
}
