/*
 * FlickeringLight.h
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef FLICKERINGLIGHT_H_
#define FLICKERINGLIGHT_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

struct LightColor {
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

	LightColor() {

	}

	LightColor(uint8_t r, uint8_t g, uint8_t b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

enum LightState {
	on,
	off,
	paused,
	disabled
};

class FlickeringLight {
public:
	FlickeringLight();
	virtual ~FlickeringLight();

	void step(void);

	void setOnCycles(unsigned int min, unsigned int max);
	void setOffCycles(unsigned int min, unsigned int max);
	void setPauseCycles(unsigned int min, unsigned int max);
	void setNoPauseCycles(unsigned int min, unsigned int max);

	void setEnabled(bool value);

	void setLightFuntion(void(*lightFunction)(const FlickeringLight*, const LightState, const bool));
	void setSoundFuntion(void(*soundFunction)(const FlickeringLight*, const LightState, const bool));

protected:
	void updateState(LightState state, bool changed);

	void(*lightFunction)(const FlickeringLight* light, const LightState state, const bool changed) = 0;
	void(*soundFunction)(const FlickeringLight* light, const LightState state, const bool changed) = 0;

private:
	LightState state = off;

	unsigned int cycle           = 10;
	unsigned int cycleMultiplier = 100;

	unsigned int onCycleMin = 1;
	unsigned int onCycleMax = 5;

	unsigned int offCycleMin = 1;
	unsigned int offCycleMax = 5;

	unsigned int noPauseCycle = 10;
	unsigned int noPauseCycleMin = 10;
	unsigned int noPauseCycleMax = 200;

	unsigned int pauseCycleMin = 10;
	unsigned int pauseCycleMax = 200;
};

#endif /* FLICKERINGLIGHT_H_ */
