#include <msp430.h> 
#include "multipleBlinkFR.h"

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    multipleBlinkFR();
	return 0;
}
