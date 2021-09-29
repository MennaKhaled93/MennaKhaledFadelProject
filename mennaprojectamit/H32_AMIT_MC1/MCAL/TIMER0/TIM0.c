/*
  Author:  Mohamed Abdulaal
  Date:    9/14/2019
  Version: 1.0
 */

#include "../../Bit_Math.h"
#include "../../STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include"../TIMER0/TIM0.h"
#include"../TIMER0/TIM0_cfg.h"

void (*ovfCallback)(void);
void (*cmCallback)(void);


void stub1(void)
{

}

void stub2(void)
{

}


ISR(TIMER0_OVF_vect){
	ovfCallback();
}


ISR(TIMER0_COMP_vect){
	cmCallback();
}


void TIM0_init(void)
{
	ovfCallback = stub1;
	cmCallback = stub2;

	TCNT0 = TIM0_TCNT0_INIT;
	OCR0 = TIM0_OCR0_INIT;


	if(TIM0_MODE_SELECT == TIM0_NORMAL_MODE)
	{
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
	}
	else if(TIM0_MODE_SELECT == TIM0_CTC_MODE)
	{
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
	}


	if(TIM0_PRESCALER_SELECT == TIM0_NO_CLK_SELECT)
	{
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
	else if(TIM0_PRESCALER_SELECT == TIM0_NO_PRESCALER_SELECT)
	{
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
	else if(TIM0_PRESCALER_SELECT == TIM0_8_PRESCALER_SELECT)
	{
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
	else if(TIM0_PRESCALER_SELECT == TIM0_64_PRESCALER_SELECT)
	{
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
	else if(TIM0_PRESCALER_SELECT == TIM0_256_PRESCALER_SELECT)
	{
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	}
	else if(TIM0_PRESCALER_SELECT == TIM0_1024_PRESCALER_SELECT)
	{
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
	}



	if(TIM0_COMPARE_MATCH_MODE_SELECT == TIM0_COMPARE_MATCH_NORMAL_MODE)
	{
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	}
	else if(TIM0_COMPARE_MATCH_MODE_SELECT == TIM0_COMPARE_MATCH_TOGGLE_MODE)
	{
		SET_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	}
	else if(TIM0_COMPARE_MATCH_MODE_SELECT == TIM0_COMPARE_MATCH_CLEAR_MODE)
	{
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	}
	else if(TIM0_COMPARE_MATCH_MODE_SELECT == TIM0_COMPARE_MATCH_SET_MODE)
	{
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	}

	if(TIM0_COMPARE_MATCH_INT_MODE == ENABLED){
		SET_BIT(TIMSK,0);
	}else{
		CLR_BIT(TIMSK,0);
	}
}

void TIM0_overFlowIntState(unsigned char state)
{
	if(state == TIM0_OVF_INT_ENABLE)
	{
		SET_BIT(TIMSK,0);
	}
	else if(state == TIM0_OVF_INT_DISABLE)
	{
		CLR_BIT(TIMSK,0);
	}
}

void TIM0_compareMatchIntState(unsigned char state)
{
	if(state == TIM0_CM_INT_ENABLE)
	{
		SET_BIT(TIMSK,1);
	}
	else if(state == TIM0_CM_INT_DISABLE)
	{
		CLR_BIT(TIMSK,1);
	}
}

void TIM0_setTCNT0(unsigned char value)
{
	TCNT0 = value;
}

void TIM0_setOCRO(unsigned char value)
{
	OCR0 = value;
}

void TIM0_forceOutputCompare(unsigned char state)
{
	if(state == TIM0_CMO_ENABLE)
	{
		SET_BIT(TCCR0,7);
	}
	else if(state == TIM0_CMO_DISABLE)
	{
		CLR_BIT(TCCR0,7);
	}

}

void TIM0_setOvfIntCallback(void (*callbackPtr)(void))
{
	ovfCallback = callbackPtr;
}

void TIM0_setCmIntCallback(void (*callbackPtr)(void))
{
	cmCallback = callbackPtr;
}
