/*
 * External_Interrupt.c
 *
 *  Created on: Oct 3, 2020
 *      Author: Mohamed Abdalla
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../External_Interrupt/External_Interrupt.h"
#include "../External_Interrupt/Interrupt_config.h"

void (*p2f0)(void);
void (*p2f1)(void);
void (*p2f2)(void);

void init_interrupt() {
#if EXTI_INT0 == ENABLED
	GICR |=(1<<INT0); //Enable INT0
#else
	GICR &=~(1<<INT0);
#endif

#if EXTI_INT0_EDGE == Low_Level
	MCUCR &= ~(1 << ISC01);
	MCUCR &= ~(1 << ISC00);
#elif EXTI_INT0_EDGE == Both_Edges
	MCUCR &=~(1<<ISC01);
	MCUCR |=(1<<ISC00);
#elif EXTI_INT0_EDGE == Falling_Edge
	MCUCR |=(1<<ISC01);
	MCUCR &=~(1<<ISC00);
#elif EXTI_INT0_EDGE == Raising_Edge
	MCUCR |=(1<<ISC01);
	MCUCR |=(1<<ISC00);
#endif

//#endif

	if (EXTI_INT1 == ENABLED) {
		GICR |= (1 << INT1);	// Enable INT1

		if (EXTI_INT1_EDGE == Low_Level) {
			MCUCR &= ~(1 << ISC11);
			MCUCR &= ~(1 << ISC10);
		} else if (EXTI_INT1_EDGE == Both_Edges) {
			MCUCR &= ~(1 << ISC11);
			MCUCR |= (1 << ISC10);
		} else if (EXTI_INT1_EDGE == Falling_Edge) {
			MCUCR |= (1 << ISC11);
			MCUCR &= ~(1 << ISC10);
		} else if (EXTI_INT1_EDGE == Raising_Edge) {
			MCUCR |= (1 << ISC11);
			MCUCR |= (1 << ISC10);
		}
	}

	if (EXTI_INT2 == ENABLED) {
		GICR |= (1 << INT2);	// Enable INT2

		if (EXTI_INT1_EDGE == Falling_Edge) {
			MCUCSR &= ~(1 << ISC2);
		} else if (EXTI_INT1_EDGE == Raising_Edge) {
			MCUCSR |= (1 << ISC2);
		}
	}

	SREG |= (1 << 7);
}

void Set_CallBack_INT0(void (*p2func)(void)){
	p2f0 = p2func;
}

void Set_CallBack_INT1(void (*p2func)(void)){
	p2f1 = p2func;
}

void Set_CallBack_INT2(void (*p2func)(void)){
	p2f2 = p2func;
}

ISR(INT0_vect){
	p2f0();
}

ISR(INT1_vect){
	p2f1();
}

ISR(INT2_vect){
	p2f2();
}
