/*
 * main.c
 *
 * author: Alican Bayındır
 *
 * Description: The code blinks the LED that connected to the PA_0 with the given interval.
 *
 * Problem 1 [20 pts]. Write a program to blink an external LED at roughly 1 second intervals.
 * Capture scope output.
 * Is there any difference between the code size when you implemented this in assembly? What do you think accounts for that?
 * Is the delay number different then the assembly implementation? Explain.
 * Change the optimization to -O2, and try again, is there any change? If so, explain what happened.
 * Is there any difference between the code sizes?
 *
 */

#include "stm32g0xx.h"

#define LEDDELAY    1600000

void delay(volatile uint32_t);

int main(void) {

    /* Enable GPIOA clock */
    RCC -> IOPENR |= (1U);

    /* Setup PA_0 as output */
    GPIOA -> MODER &= ~(1U << 1);

    /* Turn on LED */
    GPIOA -> ODR |= (1U);

    while(1) {
        delay(LEDDELAY);
        /* Toggle LED */
        GPIOA->ODR ^= (1U);
    }

    return 0;
}

void delay(volatile uint32_t s) {
    for(; s>0; s--);
}
