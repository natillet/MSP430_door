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

void init_LEDs(void)
{
	LED_DIR |= (LED_0 + LED_1); 	// Set P1.0 and P1.6 to output direction
	LED_OUT &= ~(LED_0 + LED_1); 	// Set the LEDs off
}

void init_button(void)
{
	P1IE |= BUTTON; 				// P1.3 interrupt enabled
	P1OUT |= BUTTON;
	P1REN |= BUTTON;
	P1IFG &= ~BUTTON; 				// P1.3 IFG cleared
}
