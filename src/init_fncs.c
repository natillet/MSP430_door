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
	LED01_DIR |= (LED_0 + LED_1); 	// Set P1.4 and P1.5 to output direction
	LED01_OUT &= ~(LED_0 + LED_1); 	// Set the LEDs off
	LED234_DIR |= (LED_2 + LED_3 + LED_4); 	// Set P2.0, P2.1, and P2.2 to output direction
	LED234_OUT &= ~(LED_2 + LED_3 + LED_4); // Set the LEDs off
}

void init_button(void)
{
	P1IE |= BUTTON; 				// P1.3 interrupt enabled
	P1OUT |= BUTTON;
	P1REN |= BUTTON;
	P1IFG &= ~BUTTON; 				// P1.3 IFG cleared
}
