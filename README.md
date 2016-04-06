# FlickeringLights

FlickeringLights is a small library for Arduino, that simulates a different lights and sounds for model railroads.

## Download

[Zip](https://github.com/fx-world/FlickeringLights/archive/master.zip)

## Usage

### Welding Light

```C++
WelderLight light = WelderLight(9, 5); // light on pin 9 and sound on pin 5

void setup() {
	light.setup();
}

void loop() {
	light.step();
	delayMicroseconds(100);
}
```

### TV Light

```C++
TVLight light = TVLight(9); // on pin 9

void setup() {
	light.setup();
}

void loop() {
	light.step();
	delayMicroseconds(100);
}
```