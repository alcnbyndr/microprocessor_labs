/*
 * main.c
 *
 * Created on: 30 Nov 2021
 *
 * author: Alican Bayındır
 *
 * Problem 2 [15 pts]. In this problem, you will work on creating an
 * accurate delay function using the SysTick exception.
 * Create a SysTick exception with 1 millisecond interrupt intervals.
 * Then create a delay_ms(..)function that will accurately wait for
 * (blocking) a given number of milliseconds.
 * Demonstrate the operation using an oscilloscope.
 * Compare this approach to the without timer approach, explain the differences.
 */

#include "stm32g0xx.h"

int count = 0;
int block = 1000000; // default  1 sec

void SysTick_Handler(void){

    GPIOA -> ODR ^= (1U << 7);

    if(count == block){
    	GPIOA -> BRR |= (1U << 7);
    	delay_ms(count);
    	GPIOA -> ODR |= (1U << 7);
    	SysTick -> VAL = 0;
    	count=0;
    }
    count++;
}

int main(void) {

	/* Enable GPIOA clock
	 * Enable GPIOB clock */
	RCC -> IOPENR |= (3U << 0);

	/* Setup PA7 as output */
	GPIOA -> MODER &= ~(3U << 2 * 7);
	GPIOA -> MODER |= (1U << 2 * 7);

	/* Clear led*/
	GPIOA -> BRR |= (1U << 7);

	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000); // 1ms
	// It should have been 1000 while ^^ making measurement

    while(1) {
    	block = 1000000;  // block time 1 second
    }
    return 0;
}

void delay_ms(volatile uint32_t s) {
    for(; s>0; s--);
}
