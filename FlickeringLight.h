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

	void setLightFuntion(void(*lightFunction)(const FlickeringLight*, const LightState));
	void setSoundFuntion(void(*soundFunction)(const FlickeringLight*, const LightState));

protected:
	void updateState(LightState state);

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

	void(*lightFunction)(const FlickeringLight*, const LightState) = 0;
	void(*soundFunction)(const FlickeringLight*, const LightState) = 0;
};

#endif /* FLICKERINGLIGHT_H_ */
