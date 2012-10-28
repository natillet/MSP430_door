/*
 * init_fncs.c
 *
 *  Created on: Oct 28, 2012
 *      Author: Elene Trull
 */

#include <msp430.h>
#include <defines.h>

void low_power_mode_with_interrupts(void)
{
	_BIS_SR(LPM4_bits + GIE); 		// Enter LPM4 w/interrupt
}

