/*
 * timer0.c
 *
 *  Created on: Aug 13, 2021
 *      Author: Mohamed Abdulaal
 */
#include<avr/io.h>
#include"../../Bit_Math.h"
#include"../../STD_Types.h"
#include "../Timer/timer0.h"
#include "../Timer/timer0_cfg.h"

void (*p2f_T0_OVF)(void);
void (*p2f_T0_OCF)(void);

void timer0_init(){
	TCNT0 = TIMER0_INIT_VALUE;

#if INT0_OV_INTERRUPT_MODE == ENABLED
	SET_BIT(TIMSK,TOIE0);
#else
	CLR_BIT(TIMSK,TOIE0);
#endif

#if INT0_OC_INTERRUPT_MODE == ENABLED
	SET_BIT(TIMSK,OCIE0);
#else
	CLR_BIT(TIMSK,OCIE0);
#endif

	/* Select Timer0 Mode */
#if TIMER0_MODE_SELECT == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER0_MODE_SELECT == TIMER0_PWM_PHASE_CORRECT
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER0_MODE_SELECT == TIMER0_CTC_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	OCR0 = TIMER0_OCR_VALUE;
	#elif TIMER0_MODE_SELECT == TIMER0_PWM_FAST
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#endif

	/* Select Compare output Mode */
#if TIMER0_COMPARE_OUTPUT_SELECT == COMPARE_OUTPUT_DISCONNECTED
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif TIMER0_COMPARE_OUTPUT_SELECT == COMPARE_OUTPUT_TOGGLE
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif TIMER0_COMPARE_OUTPUT_SELECT == COMPARE_OUTPUT_CLEAR
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif TIMER0_COMPARE_OUTPUT_SELECT == COMPARE_OUTPUT_SET
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif


	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
//
//	if(TIM0_PRESCALER_SELECT == TIM0_NO_CLK_SELECT)
//	{
//		CLR_BIT(TCCR0,0);
//		CLR_BIT(TCCR0,1);
//		CLR_BIT(TCCR0,2);
//	}
//	else if(TIM0_PRESCALER_SELECT == TIM0_NO_PRESCALER_SELECT)
//	{
//		SET_BIT(TCCR0,0);
//		CLR_BIT(TCCR0,1);
//		CLR_BIT(TCCR0,2);
//	}
//	else if(TIM0_PRESCALER_SELECT == TIM0_8_PRESCALER_SELECT)
//	{
//		CLR_BIT(TCCR0,0);
//		SET_BIT(TCCR0,1);
//		CLR_BIT(TCCR0,2);
//	}
//	else if(TIM0_PRESCALER_SELECT == TIM0_64_PRESCALER_SELECT)
//	{
//		SET_BIT(TCCR0,0);
//		SET_BIT(TCCR0,1);
//		CLR_BIT(TCCR0,2);
//	}
//	else if(TIM0_PRESCALER_SELECT == TIM0_256_PRESCALER_SELECT)
//	{
//		CLR_BIT(TCCR0,0);
//		CLR_BIT(TCCR0,1);
//		SET_BIT(TCCR0,2);
//	}
//	else if(TIM0_PRESCALER_SELECT == TIM0_1024_PRESCALER_SELECT)
//	{
//		SET_BIT(TCCR0,0);
//		CLR_BIT(TCCR0,1);
//		SET_BIT(TCCR0,2);
//	}


}

void setCallback_T0_TOV(void(*p2f)()){
	p2f_T0_OVF = p2f;
}

void setCallback_T0_OCF(void(*p2f)()){
	p2f_T0_OCF = p2f;
}
//
//ISR(TIMER0_OVF_vect){
//	p2f_T0_OVF();
//}
//
//
//ISR(TIMER0_COMP_vect){
//	p2f_T0_OCF();
//}
