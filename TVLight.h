/*
 * TVLight.h
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef TVLIGHT_H_
#define TVLIGHT_H_

#include "FlickeringLight.h"

class TVLight : public FlickeringLight {
public:
	TVLight(uint8_t pin);
	virtual ~TVLight();

	void setup();

	void setOnBrightness(unsigned int min, unsigned int max);
	void setOffBrightness(unsigned int min, unsigned int max);
	void setPauseBrightness(unsigned int min, unsigned int max);

private:
	uint8_t pin;

	unsigned int onBrightnessMin = 150;
	unsigned int onBrightnessMax = 255;

	unsigned int offBrightnessMin = 75;
	unsigned int offBrightnessMax = 175;

	unsigned int pauseBrightnessMin = 75;
	unsigned int pauseBrightnessMax = 175;

	static void defaultLightFunction(const FlickeringLight*, const LightState, const bool changed);
	static void defaultSoundFunction(const FlickeringLight*, const LightState, const bool changed);
};

#endif /* TVLIGHT_H_ */
