/*
 * bsp.h
 *
 *  Created on: 30 Kas 2021
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

#ifndef BSP_H_
#define BSP_H_

void BSP_init();

void delay(volatile unsigned int);

void BSP_led_init();
void BSP_led_set();
void BSP_led_reset();
void BSP_led_toggle();

void BSP_button_init();
int BSP_button_read();

void init_timer1();


#endif /* BSP_H_ */
