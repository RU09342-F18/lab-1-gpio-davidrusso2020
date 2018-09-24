#include <msp430.h> 
#include "buttonBlinkG2.h"

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	buttonBlinkG2(P1IN);
	return 0;
}
