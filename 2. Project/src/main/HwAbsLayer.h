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

#define PEDAL_PIN	A0		/* Arduino analogic pin */
#define PWM_PIN		8		/* Arduino PWM pin */

/*
 * External Functions
 */

void HwAbsLayer_Init(void);
void HwAbsLayer_ReadAnalogInput(unsigned int *pAnalogInput);
void HwAbsLayer_PwmOutput(byte *pPwm);

/*
 * Internal Functions
 */


#endif /* HWABSLAYER_H_ */
