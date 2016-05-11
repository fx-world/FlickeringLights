/*
 * HueMapLight.h
 *
 *  Created on: 26.04.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef HUEMAPLIGHT_H_
#define HUEMAPLIGHT_H_

#include "FlickeringLight.h"

class HueMapLight: public FlickeringLight {
public:
	HueMapLight(uint8_t index);
	virtual ~HueMapLight();

	void setHueMap(uint8_t huemap[]);
	unsigned int getNextHue();
	LightColor getNextColor(const LightState);
	LightColor convertToColor(uint8_t hue, uint8_t saturation, uint8_t lightness);


	void setOffLightness(unsigned int min, unsigned int max);
	unsigned int getOffLightnessMin() const;
	unsigned int getOffLightnessMax() const;

	void setOnLightness(unsigned int min, unsigned int max);
	unsigned int getOnLightnessMin() const;
	unsigned int getOnLightnessMax() const;

	void setPauseLightness(unsigned int min, unsigned int max);
	unsigned int getPauseLightnessMin() const;
	unsigned int getPauseLightnessMax() const;

	void setOnSaturation(unsigned int min, unsigned int max);
	unsigned int getOnSaturationMin() const;
	unsigned int getOnSaturationMax() const;

	void setOffSaturation(unsigned int min, unsigned int max);
	unsigned int getOffSaturationMin() const;
	unsigned int getOffSaturationMax() const;

	void setPauseSaturation(unsigned int min, unsigned int max);
	unsigned int getPauseSaturationMin() const;
	unsigned int getPauseSaturationMax() const;

private:
	uint8_t      index;
	uint8_t      huemap[360];
	unsigned int huesum;

	int          lastHue = -1;
	bool         shiftingMode = true;
	float        shiftPercent = 0.15;

	unsigned int onSaturationMin;
	unsigned int onSaturationMax;
	unsigned int offSaturationMin;
	unsigned int offSaturationMax;
	unsigned int pauseSaturationMin;
	unsigned int pauseSaturationMax;

	unsigned int onLightnessMin;
	unsigned int onLightnessMax;
	unsigned int offLightnessMin;
	unsigned int offLightnessMax;
	unsigned int pauseLightnessMin;
	unsigned int pauseLightnessMax;

	static void defaultLightFunction(const FlickeringLight*, const LightState);
};

#endif /* HUEMAPLIGHT_H_ */
