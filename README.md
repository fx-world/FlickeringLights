# FlickeringLights

FlickeringLights is a small library for Arduino, that simulates a different lights and sounds for model railroads.

## Download

## Usage

### Welding Light

```
void setup() {
	Serial.begin(9800);
	light.setup();
}

void loop() {
	light.step();
	delayMicroseconds(100);
}
```