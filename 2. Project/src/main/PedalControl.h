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
#define CONVERT_PWM_4	  4U
#define PEDAL_ZERO 		  10U
#define PWM_STEP 		    64U
#define SPORT_FACT      13
#define PWM_MAX         204


/*
 * Typedef
 */
typedef struct {
	unsigned int u16AnalogThrPedal;
	byte u08PwmOutput;
	int u16ConvertRangePwm;
	byte u08ConfigMode;
} sMainData;



/*
 * Variables
 */


/*
 * Functions
 */
void PedalControl_Init();
void PedalControl_PwmControlChangeState(byte NextState);
byte PedalControl_PwmControl();


#endif /* MAIN_PEDALCONTROL_H_ */
