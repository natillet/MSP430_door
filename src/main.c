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
#include <defines.h>
#include <init_fncs.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; 		// Stop watchdog timer
	init_LEDs();
	init_button();
	low_power_mode_with_interrupts();

}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	LED01_OUT ^= (LED_0 + LED_1); 	// P1.0 = toggle LEDs
	LED234_OUT ^= (LED_2 + LED_3 + LED_4); // P2.0 = toggle LEDs
	P1IFG &= ~BUTTON; 				// P1.3 IFG cleared
}

