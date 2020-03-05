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

/* ToDo [GFI] -  Remove - only for test */
int Counter = 0;
int Counter2 = 0;    

/*
 * Function: Initialize all HW ports 
 */
void HwAbsLayer_Init(void)
{
  pinMode(PEDAL_PIN, INPUT);
  pinMode (PWM_PIN, OUTPUT);     
}

/*
 * Function : Read Analogic Input 
 */
void HwAbsLayer_ReadAnalogInput(unsigned int *pAnalogInput)
{
	int lAdc = 0;  
	lAdc = analogRead(PEDAL_PIN);
	*pAnalogInput = lAdc;

  /* ToDo [GFI] - Remove - only for test */
  Counter++;
  if(Counter >= 100){
    Serial.print("lAdc = ");  
    Serial.println(lAdc);	
    Counter = 0;
  }
}


/*
 * Function : Set PWM output
 */
void HwAbsLayer_PwmOutput(byte *pPwm)
{	
	byte lPwm = 0;
	analogWrite(PWM_PIN, *pPwm);
  /* ToDo [GFI] - Remove - only for test */
  lPwm = *pPwm;
  Counter2++;
  if(Counter2 >= 100){
    Serial.print("lPwm = ");  
    Serial.println(lPwm);  
    Counter2 = 0;
  } 	
}
