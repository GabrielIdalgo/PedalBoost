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

Timer t;

/* Defines */

/* Initialization */
void setup()
{
	/* Init Timer 10 ms */
	t.every(10, Task100ms);

}

/* Main Loop */
void loop()
{
	t.update();
}

/* CallBack Timer runs every 10ms */
void Task100ms()
{

}
