#include "msp.h"
/*
 * buttonBlink432.c
 *
 *  Created on : Sep 26, 2018
 * Last edited : Sep 26, 2018
 *      Author : David Russo
 *
 * This function blinks an LED labeled LED2 blue or green, depending on if a button is pressed.
 * If the button is not pressed, LED2 blinks blue quickly. If the button is pressed, LED2
 * blinks green slowly.
 *
 */
int buttonBlink432();

int buttonBlink432()
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P2SEL0 &= (~BIT1 & ~BIT2);                // configures P2.1 and P2.2 for GPIO (Green and blue LED2)
  P2SEL1 &= (~BIT2 & ~BIT2);                // configures P2.1 and P2.2 for GPIO (Green and blue LED2)
  P1SEL0 &= ~BIT1;                          // configures P1.1 for GPIO (S1)
  P1SEL1 &= ~BIT1;                          // configures P1.1 for GPIO (S1)
  P1DIR &= ~BIT1;         // 0b00000010     // Set P1.1 input direction
  P2DIR |= (BIT1 | BIT2); // 0b11111001     // Set P2.1 and P2.2 to output direction
  P1REN |= (BIT1);        // 0b00000010     // Enable a resistor on input on button input
  P2OUT |= (BIT1);        // 0b00000010     // Presets P2.1 to on (green)
  P1OUT |= (BIT1);        // 0b00000010     // Configuring the resistor as a pull up resistor

  while(1)                                  // Infinite Loop
  {
      int button = P1IN & BIT1;             // declares variable button
      if(button == 0)                       // if button not pressed
      {
          P2OUT &= ~(BIT2);                 // P2.1 turns off
          P2OUT ^= BIT1;                    // P2.2 blinks
          int i;                            // declares counter variable, i
          for(i = 0; i <= 40000; i++)       // delay 40,000 cycles
          {                                 // wait
          }
      }
      else                                  // when button pressed
      {
          P2OUT &= ~(BIT1);                 // P2.1 turns off
          P2OUT ^= BIT2;                    // P2.2 blinks
          int i;                            // declares counter variable, i
          for(i = 0; i <= 20000; i++)       // delay 20,000 cycles
          {                                 // wait
          }
      }
  }
  return 0;
}




