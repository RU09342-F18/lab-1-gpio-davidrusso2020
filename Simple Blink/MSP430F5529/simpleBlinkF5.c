#include <msp430.h>
/*
 * simpleBlinkF5.c
 *
 *  Created on : Sep 26, 2018
 * Last edited : Sep 26, 2018
 *      Author : David Russo
 *
 * This function blinks two LEDs, LED1 and LED2, on the MSP-EXP430F5529LP development board synchronously.
 * LED1 and LED2 are blinked by configuring ports P1 and P4 as a GPIO and toggling P1.0 and P4.7 at the same time.
 *
 */
int simpleBlinkF5(void);

int simpleBlinkF5(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1SEL = 0;                                // configures P1 for GPIO
  P4SEL = 0;                                // configures P4 for GPIO
  P1DIR |= BIT0; // 0b00000001              // set P1.0 to output direction
  P4DIR |= BIT7; // 0b10000000              // set P4.7 to output direction
  P1OUT |= BIT0; // 0b00000001              // initializes P1.0 to 1 (LED 1)
  P4OUT |= BIT7; // 0b10000000              // initializes P4.7 to 1 (LED 2)
  while(1)                                  // Infinite Loop
  {
      volatile unsigned int i;
      for(i = 0; i <= 50000; i++)
      {
          if (i == 50000)
          {
              P1OUT ^= BIT0;                // Toggle LED1
              P4OUT ^= BIT7;                // Toggle LED2
          }
      }
  }
}


