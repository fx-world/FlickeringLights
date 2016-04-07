/*
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <TVLight.h>

// Declares a new TV light on pin 9
TVLight light = TVLight(9);

void setup() {
  light.setup();
}

void loop() {
  light.step();
  delayMicroseconds(100);
}
