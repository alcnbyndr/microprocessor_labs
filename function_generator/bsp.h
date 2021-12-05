/*
 * main.c
 *
 * author: Alican Bayındır
 *
 */

#ifndef BSP_H_
#define BSP_H_

#include "stm32g0xx.h"

#define PI 3.14

void BSP_delay(volatile uint32_t s);
void BSP_delay_ms(uint32_t s);
void BSP_enable_gpio(int gpiox);
void BSP_set_pin(int gpiox, int pin_num, int set_as);
void BSP_pin_reset(int gpiox, int pin_num);
void BSP_state_change(int gpiox, int pin_num);
void SysTick_Handler(void);
void BSP_pupdr_enabler(int gpiox, int pin_num);
void BSP_set_interrupt(int exti_num, pin_num);

int BSP_read_pin(int gpiox, int pin_num);
