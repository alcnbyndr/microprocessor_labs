/*
 * main.c
 *
 * author: Alican Bayındır
 *
 * Problem 1[20 pts]. Create a Board Support Package (BSP) that you will be using for the rest of the semester.
 * This BSP should only consist of board related functions. Some of these functions include:
 * Configure / turn on / turn off / toggle on-board LED.
 * Configure / read on-board button.
 * Initialize and configure the processor clock.
 * Initialize and configure the interrupts / exceptions.
 * Initialize and configure the SysTick timer. (Problem 2)
 * Initialize and configure the watchdog timer. (Problem 4)
 * Initialize and configure the timers if any.
 * Initialize and configure the external interrupts.
 */

#include "stm32g0xx.h"

void set_pin(int gpiox, int pin_num, int set_as);
void state_change(int gpiox, int pin_num);
int read_pin(int gpiox, int pin_num);


int value;

int main(void) {
	int a = 0;
	int b = 1;
	int c = 2;
	int e = 7;
	int f = 10;

	set_pin(a, f, b);

	while(1){
	state_change(a, f);
	}

    return 0;
}

#if 0
// Test bsp !!! Not important
void set_pin(int gpiox, int pin_num, int set_as){
	if(set_as == 0){
		// Configure the related pin as input
		if(0 <= gpiox < 6){
			/* 0 -> for GPIOA
			 * 1 -> for GPIOB
			 * 2 -> for GPIOC
			 * 3 -> for GPIOD
			 * 4 -> for GPIOE
			 * C - D - E ports are not advised to use for G0.
			 */
			RCC -> IOPENR |= (1U << gpiox);
			if(gpiox == 0){
			    GPIOA -> MODER &= ~(3U << 2 * pin_num);
			}
			if(gpiox == 1){
				GPIOB -> MODER &= ~(3U << 2 * pin_num);
			}
			if(gpiox == 2){
				GPIOC -> MODER &= ~(3U << 2 * pin_num);
			}
			/* Use the snippets below if you have other than G0 processor.
			if(gpiox == 3){
				GPIOD -> MODER |= (1U << pin_num);
			}
			if(gpiox == 4){
				GPIOE -> MODER |= (1U << pin_num);
			}
			if(gpiox == 5){
				GPIOF -> MODER |= (1U << pin_num);
			}
			*/
		}
	}
	if(set_as == 1){
		// Configure the related pin as output
		if(0 < gpiox < 6){
			/* 0 -> for GPIOA
			 * 1 -> for GPIOB
			 * 2 -> for GPIOC
			 * 3 -> for GPIOD
			 * 4 -> for GPIOE
			 * C - D - E ports are not advised to use for G0.
			 */
			RCC -> IOPENR |= (1U << gpiox);
			if(gpiox == 0){
				GPIOA -> MODER &= ~(3U << 2 * pin_num);
				GPIOA -> MODER |= (1U << 2 * pin_num);
			}
			if(gpiox == 1){
				GPIOB -> MODER &= ~(3U << 2 * pin_num);
				GPIOB -> MODER |= (1U << 2 * pin_num);
			}
			if(gpiox == 2){
				GPIOC -> MODER &= ~(3U << 2 * pin_num);
				GPIOC -> MODER |= (1U << 2 * pin_num);
			}
			/* Use the snippets below if you have other than G0 processor.
			if(gpiox == 3){
				GPIOD -> MODER |= (1U << pin_num);
			}
			if(gpiox == 4){
				GPIOE -> MODER |= (1U << pin_num);
			}
			if(gpiox == 5){
				GPIOF -> MODER |= (1U << pin_num);
			}
			*/
		}
	}
}

void state_change(int gpiox, int pin_num){
	if(gpiox == 0){
		GPIOA -> ODR ^= (1U << pin_num);
	}
	if(gpiox == 1){
		GPIOB -> ODR ^= (1U << pin_num);
	}
	if(gpiox == 2){
		GPIOC -> ODR ^= (1U << pin_num);
	}
}

int read_pin(int gpiox, int pin_num){
	if(gpiox == 0){
		value = GPIOA->IDR &= (1U << pin_num);
	}
	if(gpiox == 1){
		value = GPIOB->IDR &= (1U << pin_num);
	}
	if(gpiox == 2){
		value = GPIOC->IDR &= (1U << pin_num);
	}
	return value;
}
#endif

