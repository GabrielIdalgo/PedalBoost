/*
 * HwAbsLayer.cpp
 *
 *  Created on: 1 de fev de 2020
 *      Author: Gabriel
 */

/*
 * Libraries includes
 */

#include "HwAbsLayer.h"

void HwAbsLayer_ReadAnalogInput(unsigned int *pAnalogInput)
{
	pAnalogInput = analogRead(PEDAL_PIN);

	/* ToDo [RY]- Verify error return */
}

int HwAbsLayer_PwmOutput(byte *pPwm)
{
	unsigned int lResult = 0;
	lResult = analogWrite(pPwm);
	return lResult;
	/* ToDo [RY]- Verify error return */
}

