#include <msp430.h>
/*
 *  Created on : Sep 19, 2018
 * Last edited : Sep 19, 2018
 *      Author : David Russo
 *
 * This function blinks two LEDs, D1 and D2, on the MSPEXP430G2553 development board asynchronously.
 * D1 and D2 are blinked by configuring port P1 as a GPIO and toggling P1.0 and P1.6 at different time intervals.
 *
 */

int multipleBlinkG2(void);

int multipleBlinkG2(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1SEL = 0;                                // configures P1 for GPIO
  P1DIR |= 0x41; // 0b0100_0001             // Sets P1.0 and P1.6 to output direction
  P1OUT |= 0x41; // 0b0100_0001             // Initially sets P1.0 and P1.6 both to 1
  while(1)                                  // Infinite loop
  {
      P1OUT ^= 0x41; // 0b0100_0001         // Toggle BIT0 and BIT6

      volatile unsigned int i;              // i is a counter
      for(i = 0; i <= 12000; i++)           // i counts up to 12000
      {
          if (i % 1500 == 0)                // P1.0 switches states every 1500
              P1OUT ^= 0x01;
          if (i % 2000 == 0)                // P1.6 switches states every 2000
              P1OUT ^= 0x40;
      }
  }
}
