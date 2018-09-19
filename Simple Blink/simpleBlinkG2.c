#include <msp430.h>
/*
 *  Created on : Sep 19, 2018
 * Last edited : Sep 19, 2018
 *      Author : David Russo
 *
 * This function blinks two LEDs, D1 and D2, on the MSPEXP430G2553 development board synchronously.
 * D1 and D2 are blinked by configuring port P1 as a GPIO and toggling P1.0 and P1.6 at the same time.
 *
 */
int simpleBlinkG2(void);

int simpleBlinkG2(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1SEL = 0;                                // configures P1 for GPIO
  P1DIR |= 0x41; // 0b01000001              // Set P1.0 and P1.6 to output direction
  P1OUT |= 0x41; //
  while(1)                                  // Infinite Loop
  {
//      P1OUT ^= 0x41; // 0b01000001          // Set BIT0 and BIT6 = 1

      volatile unsigned int i;
      for(i = 0; i <= 50000; i++)
      {
          if (i == 50000)
              P1OUT ^= 0x41;
      }
  }
}
