/*
 * main.c
 *
 * author: Alican Bayındır
 *
 */

#include "bsp.h"
#include "time.h"
#include "math.h"
#include "stm32g0xx.h"

#define LEDDELAY    1600000


void BSP_delay(volatile uint32_t s) {
    for(; s>0; s--);
}

void BSP_delay_ms(uint32_t s) {
    tick = 0;
    while(tick);
}

// use the function below before using any GPIO based process'
void BSP_enable_gpio(int gpiox){
	/* 0 -> for GPIOA
	 * 1 -> for GPIOB
	 * 2 -> for GPIOC
	 * 3 -> for GPIOD
	 * 4 -> for GPIOE
	 * C - D - E ports are not advised to use for G0.
	 */
	RCC -> IOPENR |= (1U << gpiox);
}

// Test bsp !!! Not important
// As I use g0 processor there is no need of GPIO_D,E,F so,
// I made them comment
void BSP_set_pin(int gpiox, int pin_num, int set_as){
	/* 0 -> for GPIOA
	 * 1 -> for GPIOB
	 * 2 -> for GPIOC
	 * 3 -> for GPIOD
	 * 4 -> for GPIOE
	 * C - D - E ports are not advised to use for G0.
	 * ---------------PIN_NUM--------------------
	 * give a number according to microprocessors pins
	 * -----------------SET_AS-------------------
	 * 0 -> to set it as input
	 * 1 -> to set it as output
	 */
	if(set_as == 0){
		// Configure the related pin as input
		if(0 <= gpiox < 6){
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


void BSP_pin_reset(int gpiox, int pin_num){
	if(0 < gpiox < 3){
		if(gpiox == 0){
			GPIOA -> BRR |= (1U << pin_num);
		}
		if(gpiox == 1){
			GPIOB -> BRR |= (1U << pin_num);
		}
		if(gpiox == 2){
			GPIOC -> BRR |= (1U << pin_num);
		}
	}
}


// Reverses the input given to a pin
void BSP_state_change(int gpiox, int pin_num){
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

// The read_pin function may not be function due to some reset states in
// the processor *****BE CAREFUL****** whilst using it
int BSP_read_pin(int gpiox, int pin_num){
	if(gpiox == 0){
		int value = GPIOA->IDR &= (1U << pin_num);
	}
	if(gpiox == 1){
		int value = GPIOB->IDR &= (1U << pin_num);
	}
	if(gpiox == 2){
		int value = GPIOC->IDR &= (1U << pin_num);
	}
	return value;
}

void SysTick_Handler(void) {
	if(tick > 0){
		--tick;
	}
}

void BSP_pupdr_enabler(int gpiox, int pin_num){
	if(0 < gpiox < 3){
		if(gpiox == 0){
			GPIOA -> PUPDR |= (2U << 2 * pin_num);
		}
		if(gpiox == 1){
			GPIOB -> PUPDR |= (2U << 2 * pin_num);
		}
		if(gpiox == 2){
			GPIOC -> PUPDR |= (2U << 2 * pin_num);
		}
	}
}

// Set interrupt for inputs
void BSP_set_interrupt(int exti_num, pin_num){
	/* TODO
	 * 1- Set EXTI
	 * 2- Set rising edge - falling edge
	 * 3- Mask the pin
}

/* TODOs
 * SSD set
 * SSD toggle
 * SSD change state
 * KEYPAD set
 * KEYPAD control
 */
