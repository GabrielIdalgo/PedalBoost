/*
 * PedalControl.h
 *
 *  Created on: 1 de fev de 2020
 *      Author: Gabriel
 */

#ifndef MAIN_PEDALCONTROL_H_
#define MAIN_PEDALCONTROL_H_


/*
 * Libraries includes
 */

#include "Arduino.h"
#include "HwAbsLayer.h"

#define PwmSteps 256U

typedef struct {
	unsigned int u16AnalogThrPedal;
	byte u08PwmOutput[PwmSteps];
} sMainDataExtern;


unsigned int u16PedalCourse = 0;

byte PedalControl_ChangePwmControl();

#endif /* MAIN_PEDALCONTROL_H_ */
