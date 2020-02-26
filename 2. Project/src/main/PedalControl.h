/*
 * PedalControl.h
 *
 *  Created on: 1 de fev de 2020
 *      Author: Gabriel
 */

#ifndef MAIN_PEDALCONTROL_H_
#define MAIN_PEDALCONTROL_H_


/*
 * Includes
 */
#include "Arduino.h"
#include "HwAbsLayer.h"
#include "Comm_appl.h"


/*
 * Defines
 */
#define CONVERT_PWM_2 	2U
#define CONVERT_PWM_4	4U
#define PEDAL_ZERO 		10U
#define PWM_STEP 		64U


/*
 * Typedef
 */
typedef struct {
	unsigned int u16AnalogThrPedal;
	byte u08PwmOutput;
	int u16ConvertRangePwm;
	PedalCtrl u08ConfigMode;
} sMainData;



/*
 * Variables
 */
unsigned int u16PedalCourse;
byte SportConvTable[PWM_STEP] = { 0, 10, 30, 50,
		60, 80, 100, 103, 105, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 235, 240, 245,
		246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256,
		256, 256, 256, 256,	256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256 };

/*
 * Functions
 */
void PedalControl_Init();
void PedalControl_PwmControlChangeState(PedalCtrl NextState);
byte PedalControl_PwmControl();


#endif /* MAIN_PEDALCONTROL_H_ */
