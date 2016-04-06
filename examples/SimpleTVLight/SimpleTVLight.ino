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
