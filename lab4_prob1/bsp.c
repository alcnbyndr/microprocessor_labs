/*
 * bsp.h
 *
 * Created on: 30 Nov 2021
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


#include "bsp.h"
#include "stm32g0xx.h"

void BSP_system_init(){
	SystemCoreClockUpdate();
	BSP_led_init();
	BSP_button_init();
	SysTick_Config(SystemCoreClock / 1000);
}

void init_timer1(){
	RCC -> APBENR2 |= (1U << 11);

	TIM1 -> CR1 = 0;
	TIM1 -> CR1 |= (1 << 7);
	TIM1 -> CNT = 0;

	TIM1 -> PSC = 999;
	TIM1 -> ARR = 16000;

	TIM1 -> DIER |= (1 << 0);
	TIM1 -> CR1 |= (1 << 0);

	NVIC_SetPriortiy(TIM1_BRK_UP_TRG_COM_IRQn, 1);
	NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
}

void BSP_led_init(void){
    /* Enable GPIOC clock */
    RCC -> IOPENR |= (1U << 2);

    /* Setup PC6 as output */
    GPIOC -> MODER &= ~(3U << 2 * 6);
    GPIOC -> MODER |= (1U << 2 * 6);

    /* Turn on LED */
    GPIOC -> BRR |= (1U << 6);
}

void BSP_led_set(void){
    GPIOC -> ODR |= (1U << 6);
}

void BSP_led_reset(void){
    GPIOC -> BRR |= (1U << 6);
}

void BSP_led_toggle(void){
    GPIOC->ODR ^= (1U << 6);
}

void delay(volatile uint32_t s) {
    for(; s>0; s--);
}

void BSP_button_init(){
	/* Enable GPIOF clock */
	RCC -> IOPENR |= (1U << 5);

	/* Setup PF2 as output */
	GPIOF -> MODER &= ~(3U << 2 * 2);
}

int BSP_button_read(){
	int button_value = ((GPIOF -> IDR >> 2) & 0x0001);
	if(b) return 0;
	else return 1;
}

