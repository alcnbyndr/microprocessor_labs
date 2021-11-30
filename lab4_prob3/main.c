/*
 * main.c
 *
 * Created on: 30 Nov 2021
 *
 * author: Alican Bayındır
 *
 * Problem 3 [45 pts].In this problem you are asked to implement a time
 * counter using SSDs. Attach 4x SSDs and using a state machine, implement
 * a time counter with different intervals. Assign each speed a modeand attach
 * a button to cycle through the modes. (Each button press will cycle through these modes.)
 * ●You should use a timer interrupt to display a given number on an SSD.
 * ●Another timer should do the counting.
 * ●This is the final implementation on how you should use the Seven Segment Display.
 * Modes:
 * ●Mode 0 → No countdown (0 secondinterval)
 * ●Mode 1 → Count down speed is×1, with1 second intervals.
 * ●Mode 2 → Count down speed is×2, with.5 second intervals
 * ●Mode 3 → Count down speed is×10, with.1 second intervals
 * ●Mode 4 → Count down speed is ×100, with .01 second intervals
 * ●Mode 5 → Count down speed is ×1000, with .001 second intervalsWarnings:
 * ●Define an enum for your states, and cycle through them in each button press.
 * ●Depending on the state, define the delay.
 * ●Your flowchart should be detailed enough and should overlap with your implementation.
 * ●Make sure your code works when the optimization is defined as
 * -O2.Requirements:
 * ●Brightness on the Seven Segments should be equal.
 * ●No bouncing on the buttons.
 * ●Start from 00:00,23:59, 23:58,... and go down to 00:00 and keep counting again(free running time counter).
 * The four SSDs must show the countdownas“minute:second”formatwithout colon(:).
 * For Mode 1,counting down must take 24 minutes to complete.For the other mode sit should takeless than 24 minutes,
 * inversely proportional to the speed.
 * */

#include "stm32g0xx.h"
int i, j, k, l;
int count=0;

interval=1000000;

enum mode{m0,m1,m2,m3,m4,m5}state;


void EXTI2_3_IRQHandler(void) {

	if (state != 5) {
	state ++;
	}
	else {
	state = 0;
	}
	switch(state){
	case 0:
		delay(1000000);
		while(1){
		if((GPIOB->IDR >> 3) & 1){
			break;
		}
		run();
		}
	case 1:
		interval=1000000;
	break;
	case 2:
		interval=500000;
	break;
	case 3:
		interval=100000;
	break;
	case 4:
		interval=10000;
	break;
	case 5:
		interval=1000;
	break;
	}

EXTI->RPR1 |= (1U << 3);
}

void SysTick_Handler(void)  {

run();


   SysTick->VAL = 0;
}

int main(void) {
state=0;
	/*Enable GPIOA clock */
	RCC->IOPENR |= (1U << 0);
	/*Enable GPIOB clock */
	RCC->IOPENR |= (1U << 1);

	  /* setup PB(0,1,2,8) for seven segment D4,D3,D2,D1 for in MODER */
	     GPIOB->MODER &= ~(0x3003F);
	     GPIOB->MODER |= (0x10015);

	/* Setup PA0, PA1, PA4, PA5, PA12, PA11, PA6 as output for SSD */
	GPIOA->MODER &= ~(3U << 2*0);
	GPIOA->MODER |=  (1U << 2*0);  // PA0 is output

	GPIOA->MODER &= ~(3U << 2*1);
	GPIOA->MODER |=  (1U << 2*1);  // PA1 is output

    GPIOA->MODER &= ~(3U << 2*4);
	GPIOA->MODER |=  (1U << 2*4);  // PA4 is output

	GPIOA->MODER &= ~(3U << 2*5);
	GPIOA->MODER |=  (1U << 2*5);  // PA5 is output

	GPIOA->MODER &= ~(3U << 2*12);
	GPIOA->MODER |=  (1U << 2*12);  // PA12 is output

	GPIOA->MODER &= ~(3U << 2*11);
	GPIOA->MODER |=  (1U << 2*11);  // PA11 is output

	GPIOA->MODER &= ~(3U << 2*6);
	GPIOA->MODER |=  (1U << 2*6);  // PA6 is output
/* Setup PB3 as input */
	GPIOB->MODER &= ~(3U << 2*3);

	EXTI->RTSR1 |= (1U << 3); // B3
	EXTI->EXTICR[0] |= (1U << 8*3);
	EXTI->IMR1 |= (1U << 3);

	NVIC_SetPriority(EXTI2_3_IRQn, 0);
	NVIC_EnableIRQ(EXTI2_3_IRQn);


  SysTick_Config(SystemCoreClock/100);
int a;
	while(1) {
		clearSSD();
//initial values for 00:00
		i=0,j=0,k=0,l=0;
		delay(1000000);
		for(l=2;l>=0;l--){
			delay(1000);
			if(l==2){
				a=3;
			}else{
				a=9;
			}
		for(k=a;k>=0;k--){
			delay(1000);
for(j=5;j>=0;j--){
delay(1000);
		for(i=9;i>=0;i--){
delay(interval);
		}
}
	}
	}
	}
	return 0;
}






void clearSSD(void){
	/* Set all outputs connected to SSD (clear SSD) */
	GPIOA->ODR |= (1U << 0);   // PA0  A
	GPIOA->ODR |= (1U << 1);   // PA1  B
	GPIOA->ODR |= (1U << 4);   // PA4  C
	GPIOA->ODR |= (1U << 5);   // PA5  D
	GPIOA->ODR |= (1U << 12);  // PA12 E
	GPIOA->ODR |= (1U << 11);  // PA11 F
	GPIOA->ODR |= (1U << 6);   // PA6  G
}
void setSSD( int x ) {
	clearSSD();
	switch ( x )
	{
	case 0:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 12);  // PA12 E
		GPIOA->ODR &= ~(1U << 11);  // PA11 F
		break;

	case 1:
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		break;

	case 2:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 12);  // PA12 E
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;

	case 3:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;

	case 4:
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 11);  // PA11 F
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;

	case 5:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 11);  // PA11 F
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;

	case 6:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 12);  // PA12 E
		GPIOA->ODR &= ~(1U << 11);  // PA11 F
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;

	case 7:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		break;

	case 8:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 12);  // PA12 E
		GPIOA->ODR &= ~(1U << 11);  // PA11 F
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;

	case 9:
		GPIOA->ODR &= ~(1U << 0);   // PA0  A
		GPIOA->ODR &= ~(1U << 1);   // PA1  B
		GPIOA->ODR &= ~(1U << 4);   // PA4  C
		GPIOA->ODR &= ~(1U << 5);   // PA5  D
		GPIOA->ODR &= ~(1U << 11);  // PA11 F
		GPIOA->ODR &= ~(1U << 6);   // PA6  G
		break;
	}
}


void on_SSD1() {/* turn on SSD 1(LEFT).*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x100);
}
void off_SSD1() {/* turn off SSD 1(LEFT).*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x100);
}
void on_SSD2() {/* turn on SSD 2.*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x4);
}
void off_SSD2() {/* turn off SSD 2.*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x4);
}
void on_SSD3() {/* turn on SSD 3.*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x1);
}
void off_SSD3() {/* turn off SSD 3.*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x1);
}
void on_SSD4() {/* turn on SSD 4.*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x2);
}
void off_SSD4() {/* turn off SSD 4.*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x2);
}

void delay_ms(volatile uint32_t s) {
    for(; s>0; s--);
}

void delay(volatile uint32_t s) {
    for(; s>0; s--);
}

void run(){
	       on_SSD1();
		   setSSD(l);
		   delay(3250);
		   off_SSD1();
		   delay(100);

		   on_SSD2();
		   setSSD(k);
		   delay(3250);
		   off_SSD2();
		   delay(100);

		   on_SSD3();
		   setSSD(j);
		   delay(3250);
		   off_SSD3();
		   delay(100);

		   on_SSD4();
		   setSSD(i);
		   delay(3250);
		   off_SSD4();
		   delay(100);
}
