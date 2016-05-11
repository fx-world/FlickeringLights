/*
 * ColorTVLight.h
 *
 *  Created on: 08.05.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef COLORTVLIGHT_H_
#define COLORTVLIGHT_H_

#include "HueMapLight.h"

class ColorTVLight : public HueMapLight {
public:
	ColorTVLight(uint8_t index, uint8_t soundPin = 0);
	virtual ~ColorTVLight();

	void setup();

private:
	uint8_t soundPin = 0;
	static void defaultSoundFunction(const FlickeringLight*, const LightState, const bool changed);
};

#endif /* COLORTVLIGHT_H_ */
