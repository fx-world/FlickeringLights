/*
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <WelderLight.h>

// Declares a new welding light on pin 9 and sound on pin 6
WelderLight light = WelderLight(9, 6);

void setup() {
  light.setup();
}

void loop() {
  light.step();
  delayMicroseconds(100);
}
