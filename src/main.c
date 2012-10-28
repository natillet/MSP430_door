//***************************************************************************************
//  MSP430 RFID door lock
//
//  Description: Lock and unlock a door with an RFID key
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Elene Trull
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>
//#include "../inc/defines.h"
//#include "../inc/init_fncs.h"
#include <defines.h>
#include <init_fncs.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; 		// Stop watchdog timer
	LED_DIR |= (LED_0 + LED_1); 	// Set P1.0 and P1.6 to output direction
	LED_OUT &= ~(LED_0 + LED_1); 	// Set the LEDs off
	P1IE |= BUTTON; 				// P1.3 interrupt enabled
	P1OUT |= BUTTON;
	P1REN |= BUTTON;
	P1IFG &= ~BUTTON; 				// P1.3 IFG cleared
	low_power_mode_with_interrupts();

}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	LED_OUT ^= (LED_0 + LED_1); 	// P1.0 = toggle LEDs
	P1IFG &= ~BUTTON; 				// P1.3 IFG cleared
}

