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

class FlickeringLight {
public:
	FlickeringLight();
	virtual ~FlickeringLight();

	void step(void);

	void setOnCycles(unsigned int min, unsigned int max);
	void setOffCycles(unsigned int min, unsigned int max);
	void setPauseCycles(unsigned int min, unsigned int max);
	void setNoPauseCycles(unsigned int min, unsigned int max);

	void setDebug(bool value);

protected:
	virtual void updateState(bool state, bool pause);

public:
	bool debug = false;
	bool state = false;
	bool pause = false;

	unsigned int cycle           = 10;
	unsigned int  cycleMultiplier = 100;

	unsigned int  onCycleMin = 1;
	unsigned int  onCycleMax = 5;

	unsigned int  offCycleMin = 1;
	unsigned int  offCycleMax = 5;

	unsigned int  noPauseCycle = 10;
	unsigned int  noPauseCycleMin = 10;
	unsigned int  noPauseCycleMax = 200;

	unsigned int  pauseCycleMin = 10;
	unsigned int  pauseCycleMax = 200;
};

#endif /* FLICKERINGLIGHT_H_ */
