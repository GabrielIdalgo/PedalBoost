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

/* Headers includes */
#include "main.h"

Timer t;

/* Defines */

/* Initialization */
void setup()
{
	/* Init Timer 100 ms */
	t.every(100, Task100ms);

}

/* Main Loop */
void loop()
{
	t.update();
}

/* CallBack Timer runs every 100ms */
void Task100ms()
{

}
