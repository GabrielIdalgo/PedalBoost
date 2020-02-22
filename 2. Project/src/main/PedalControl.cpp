/*
 * PedalControl.cpp
 *
 *  Created on: 1 de fev de 2020
 *      Author: Gabriel
 */

#include "PedalControl.h"
#include "Comm_appl.h"

sMainDataExtern MainDataEx;

byte PedalControl_PwmControl()
{
	byte u08lResult = 0;
	bute u08ConfigMode = 0;
	HwAbsLayer_ReadAnalogInput(&MainDataEx->u16AnalogThrPedal);


	switch(u08ConfigMode)
	{
		case PedalCtr_Off:
		{
			break;
		}
		case PedalCtr_Sport:
		{
			break;
		}
		case PedalCtr_Protect:
		{
			break;
		}
		default:
		{

		}
	}

	return u08lResult;
}

byte PedalControl_ConvTableThro(unsigned int *pAnalogPedal)
{
	/* ToDo [RY]- Use bluetooth info */
}
