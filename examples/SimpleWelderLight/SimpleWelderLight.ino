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
