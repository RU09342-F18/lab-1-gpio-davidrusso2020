#include <msp430.h>
/*
 *  Created on : Sep 26, 2018
 * Last edited : Sep 26, 2018
 *      Author : David Russo
 *
 * This function blinks two LEDs, LED1 and LED2, on the MSP-EXP430FR2311 development board asynchronously.
 * LED1 and LED2 are blinked by configuring ports P1 and P2 as a GPIO and toggling P1.0 and P2.0 at different time intervals.
 *
 */

int multipleBlinkFR(void);

int multipleBlinkFR(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  // Disable the GPIO power-on default high-impedance mode
  // to activate previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  P1SEL0 &= ~BIT0;                          // configures P1.0 for GPIO
  P1SEL1 &= ~BIT0;                          // configures P1.0 for GPIO
  P2SEL0 &= ~BIT0;                          // configures P2.0 for GPIO
  P2SEL1 &= ~BIT0;                          // configures P2.0 for GPIO
  P1DIR |= BIT0; // 0b00000001              // sets P1.0 to output direction
  P2DIR |= BIT0; // 0b00000001              // sets P2.0 to output direction
  P1OUT |= BIT0; // 0b00000001              // initially sets P1.0 to 1
  P2OUT |= BIT0; // 0b00000001              // initially sets P2.0 to 1
  volatile unsigned int i, j;               // i is a counter declared outside of the loop
  while(1)                                  // infinite loop
  {
      if (i == 15000)                       // checks if i equals 150000
      {
          P1OUT ^= BIT0;                    // P1.0 toggles
          i = 0;                            // i is reset to 0
      }
      else if (j == 10000)                  // checks if j equals 100000
      {
          P2OUT ^= BIT0;                    // P2.0 toggles
          j = 0;                            // j is reset to 0
      }
      i++;                                  // increment i
      j++;                                  // increment j
  }                                         // end loop
}
