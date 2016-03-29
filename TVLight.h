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

#define TV_LIGHT_10ms 0
#define TV_LIGHT_100us 10

class TVLight : public FlickeringLight {
public:
	TVLight(uint8_t pin);
	virtual ~TVLight();

	void setup();

protected:
	void updateState(bool state, bool pause);

private:
	uint8_t pin;
};

#endif /* TVLIGHT_H_ */
