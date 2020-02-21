/* PedalBooster project main file
 * Developer: Gabriel Idalgo / Pablo Silva
 *
 * ToDo[idalgo] - need to improve the comments
 */

/* Libraries includes */


/* Headers includes */
#include "main.h"

/* Libraries includes */
#include <Event.h>
#include <Timer.h>

/* Local Variables */
Timer t;
MainData_t mainData;

/* Defines */

/* Initialization */
void setup()
{
	/* Init Timer 10 ms */
	t.every(10, Task100ms);
	Serial.begin(115200);
	Serial1.begin(9600);

}

/* Main Loop */
void loop()
{
	t.update();
}

/* CallBack Timer runs every 10ms */
void Task100ms()
{
	Comm_appl_FSM(&mainData.uart);
	Comm_appl_FRM(&mainData.uart);
	Comm_appl_RHM(&mainData.uart);  
  
}
