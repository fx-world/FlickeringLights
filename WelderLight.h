/*
 * WelderLight.h
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef WELDERLIGHT_H_
#define WELDERLIGHT_H_

#include "FlickeringLight.h"

class WelderLight : public FlickeringLight {
public:
	WelderLight(uint8_t pin);
	WelderLight(uint8_t pin, uint8_t soundPin);
	virtual ~WelderLight();

	void setup();

	void setSound(int min, int max);

protected:
	void updateState(bool state, bool pause);

private:
	uint8_t pin;
	uint8_t soundPin = -1;

	int  soundMin = 6000;
	int  soundMax = 8000;

};

#endif /* WELDERLIGHT_H_ */
