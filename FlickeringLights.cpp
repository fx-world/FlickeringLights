/*
 * FlickeringLights.cpp
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <Arduino.h>
#include "WelderLight.h"
#include "TVLight.h"

WelderLight light = WelderLight(9,6);

void setup() {
	light.setup();
}

void loop() {
	light.step();
	delayMicroseconds(100);
}
