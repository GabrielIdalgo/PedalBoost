/*
 * HwAbsLayer.h
 *
 *  Created on: 1 de fev de 2020
 *      Author: Gabriel
 */

#ifndef HWABSLAYER_H_
#define HWABSLAYER_H_

/*
 * Libraries includes
 */

#include "Arduino.h"

/*
 * Defines
 */

#define PEDAL_PIN	A8U		/* Arduino analogic pin */
#define PWM_PIN		8U		/* Arduino PWM pin */

/*
 * External Functions
 */

int HwAbsLayer_ReadAnalogInput();
int HwAbsLayer_PwmOutput(byte *pPwm);

/*
 * Internal Functions
 */


#endif /* HWABSLAYER_H_ */
