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
	LightState lastState = state;

	if ((state == on) || (state == off)) {
		cycle--;
		noPauseCycle--;

		if (cycle <= 0) {
			if (state == on) {
				state = off;
				cycle = random(offCycleMax*cycleMultiplier - offCycleMin*cycleMultiplier) + offCycleMin*cycleMultiplier;
			} else {
				state = on;
				cycle = random(onCycleMax*cycleMultiplier - onCycleMin*cycleMultiplier) + onCycleMin*cycleMultiplier;
			}
		}

		if (noPauseCycle <= 0) {
			state = paused;
			cycle = random(pauseCycleMax*cycleMultiplier - pauseCycleMin*cycleMultiplier) + pauseCycleMin*cycleMultiplier;
		}

		updateState(state, state != lastState);

	} else if (state == paused) {
		cycle--;
		if (cycle <= 0) {
			state        = on;
			noPauseCycle = random(noPauseCycleMax*cycleMultiplier - noPauseCycleMin*cycleMultiplier) + noPauseCycleMin*cycleMultiplier;
			cycle        = random(onCycleMax*cycleMultiplier - onCycleMin*cycleMultiplier) + onCycleMin*cycleMultiplier;
		}

		updateState(state, state != lastState);

	} else {
		// nothing to do when disabled
	}
}

void FlickeringLight::updateState(LightState state, bool changed) {
	if (lightFunction != 0) {
		lightFunction(this, state, changed);
	}

	if (soundFunction != 0) {
		soundFunction(this, state, changed);
	}
}

void FlickeringLight::setLightFuntion(void(*lightFunction)(const FlickeringLight*, const LightState, const bool)) {
	this->lightFunction = lightFunction;
}

void FlickeringLight::setSoundFuntion(void(*soundFunction)(const FlickeringLight*, const LightState, const bool)) {
	this->soundFunction = soundFunction;
}

void FlickeringLight::setEnabled(bool value) {
	if (value) {
		if (state == disabled) {
			state = on;
		}
	} else {
		state = disabled;
		updateState(state, true);
	}
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
