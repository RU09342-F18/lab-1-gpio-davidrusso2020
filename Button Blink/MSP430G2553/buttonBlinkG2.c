#include <msp430.h>
/*
 *  Created on : Sep 23, 2018
 * Last edited : Sep 24, 2018
 *      Author : David Russo
 *
 * This function blinks two LEDs, D1 and D2, depending on if a button is pressed
 * If the button is not pressed, D1 blinks quickly. If the button is pressed, D1
 * blinks slowly.
 *
 */
int buttonBlinkG2();

int buttonBlinkG2()
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1SEL = 0;                                // configures P1 for GPIO
  P1DIR |= (BIT0 | BIT6); // 0b01000001     // Set P1.0 and P1.6 to output direction
  P1DIR &= ~(BIT3);       // 0b11110111     // Set P1.3 to input direction
  P1REN |= (BIT3);        // 0b00001000     // Enable a resistor on input on button input
  P1OUT |= (BIT6);        // 0b01000000     // Presets P1.6 to 1
  P1OUT |= (BIT0);        // 0b00000001     // Presets P1.0 to 1
  P1OUT |= (BIT3);        // 0b00001000     // Configuring the resistor as a pull up resistor

  while(1)                                  // Infinite Loop
  {
      int button = P1IN & BIT3;             // declares variable button
      if(button == 0)                       // if button not pressed
      {
          P1OUT &= ~(BIT0);                 // P1.0 turns off
          P1OUT ^= BIT6;                    // P1.6 blinks
          int i;                            // declares counter variable, i
          for(i = 0; i <= 20000; i++)       // delay 20,000 cycles
          {                                 // wait
          }
      }
      else                                  // when button pressed
      {
          P1OUT &= ~(BIT6);                 // P1.6 turns off
          P1OUT ^= BIT0;                    // P1.0 blinks
          int i;                            // declares counter variable, i
          for(i = 0; i <= 10000; i++)       // delay 10,000 cycles
          {                                 // wait
          }
      }
  }
  return 0;
}
