/*
 * FlickeringLight.cpp
 *
 *  Created on: 26.03.2016
 *      Author: Pascal Weyprecht
 *
 * Copyright (C) 2016 Pascal Weyprecht
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "FlickeringLight.h"

FlickeringLight::FlickeringLight() {

}

FlickeringLight::~FlickeringLight() {

}

void FlickeringLight::step(void) {
	if (!pause) {
		cycle--;
		noPauseCycle--;

		if (cycle <= 0) {
			if (state) {
				state = false;
				cycle = random(offCycleMax*cycleMultiplier - offCycleMin*cycleMultiplier) + offCycleMin*cycleMultiplier;
			} else {
				state = true;
				cycle = random(onCycleMax*cycleMultiplier - onCycleMin*cycleMultiplier) + onCycleMin*cycleMultiplier;
			}
		}

		if (noPauseCycle <= 0) {
			pause = true;
			state = false;
			cycle = random(pauseCycleMax*cycleMultiplier - pauseCycleMin*cycleMultiplier) + pauseCycleMin*cycleMultiplier;
		}

		updateState(state, pause);

	} else {
		cycle--;
		if (cycle <= 0) {
			pause = false;
			noPauseCycle = random(noPauseCycleMax*cycleMultiplier - noPauseCycleMin*cycleMultiplier) + noPauseCycleMin*cycleMultiplier;

			state = true;
			cycle = random(onCycleMax*cycleMultiplier - onCycleMin*cycleMultiplier) + onCycleMin*cycleMultiplier;
		}

		updateState(state, pause);
	}
}

void FlickeringLight::updateState(bool state, bool pause) {

}

void FlickeringLight::setOnCycles(unsigned int min, unsigned int max) {
	onCycleMin = min;
	onCycleMax = max;
}

void FlickeringLight::setOffCycles(unsigned int min, unsigned int max) {
	offCycleMin = min;
	offCycleMax = max;
}

void FlickeringLight::setPauseCycles(unsigned int min, unsigned int max) {
	pauseCycleMin = min;
	pauseCycleMax = max;
}

void FlickeringLight::setNoPauseCycles(unsigned int min, unsigned int max) {
	noPauseCycleMin = min;
	noPauseCycleMax = max;
}
