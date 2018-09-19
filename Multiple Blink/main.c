#include <msp430.h> 
#include "multipleBlinkG2.h"
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	multipleBlinkG2();

	return 0;
}
