#include <msp430.h>
#include "simpleBlinkG2.h"

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    simpleBlinkG2();
    return 0;
}
