/*
 * PedalControl.cpp
 *
 *  Created on: 1 de fev de 2020
 *      Author: Gabriel
 */

#include "PedalControl.h"

sMainData MainData;

/*
*    Function: Main state machine of Pedal Control
*
*/
void PedalControl_Init()
{
	MainData.u16AnalogThrPedal = 0;
	MainData.u08PwmOutput = 0;
	MainData.u16ConvertRangePwm = 0;
	MainData.u08ConfigMode = PedalCtr_Off;
}


/*
*    Function: Change the Pedal Control machine state
*
*/
void PedalControl_PwmControlChangeState(PedalCtrl NextState)
{
	MainData.u08ConfigMode = NextState;
}

/*
*    Function: Main state machine of Pedal Control
*
*/
byte PedalControl_PwmControl()
{
	byte u08lResult = 0;
	byte u08lIndexSport = 0;
	HwAbsLayer_ReadAnalogInput(&MainData->u16AnalogThrPedal);


	switch(MainData.u08ConfigMode)
	{
		case PedalCtr_Off:
		{
			MainData.u16ConvertRangePwm = MainData.u16AnalogThrPedal;
			MainData.u16ConvertRangePwm = (MainData.u16ConvertRangePwm >> CONVERT_PWM_2);		/* number >> 2 equal number / 4  --> 1024 in 256 */
			MainData.u08PwmOutput = (byte)MainData.u16ConvertRangePwm;
			HwAbsLayer_PwmOutput(&MainData->u08PwmOutput);
			break;
		}
		case PedalCtr_Sport:
		{
			MainData.u16ConvertRangePwm = MainData.u16AnalogThrPedal;
			MainData.u16ConvertRangePwm = (MainData.u16ConvertRangePwm >> CONVERT_PWM_4);		/* number >> 4 equal number / 16  --> 1024 in 64 (Sport Table) */
			u08lIndexSport = (byte)MainData.u16ConvertRangePwm;
			MainData.u08PwmOutput = SportConvTable[u08lIndexSport];
			HwAbsLayer_PwmOutput(&MainData->u08PwmOutput);
			break;
		}
		case PedalCtr_WaitProtect:
		{
			/* ToDo [GFI][REVIEW] - If need to get a stable pedal in ZERO during a time */
			if(MainData.u16AnalogThrPedal < PEDAL_ZERO){
				PedalControl_PwmControlChangeState(PedalCtr_Protect);
			}else{
				/* Wait pedal in zero */
			}
			break;
		}
		case PedalCtr_Protect:
		{
			MainData.u08PwmOutput = 0;
			HwAbsLayer_PwmOutput(&MainData->u08PwmOutput);
			break;
		}
		default:
		{
			PedalControl_PwmControlChangeState(PedalCtr_Off);
		}
	}

	return u08lResult;
}


