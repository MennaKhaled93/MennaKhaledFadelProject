/*
 * timer0_cfg.h
 *
 *  Created on: Aug 13, 2021
 *      Author: Mohamed Abdulaal
 */
#ifndef MCAL_TIMER_TIMER0_CFG_H_
#define MCAL_TIMER_TIMER0_CFG_H_

#define TIMER0_INIT_VALUE			0
#define TIMER0_OCR_VALUE			150

/* Prescalers */
#define TIM0_NO_CLK_SELECT          0
#define TIM0_NO_PRESCALER_SELECT    1
#define TIM0_8_PRESCALER_SELECT     2
#define TIM0_64_PRESCALER_SELECT    3
#define TIM0_256_PRESCALER_SELECT   4
#define TIM0_1024_PRESCALER_SELECT  5

#define TIM0_PRESCALER_SELECT 	TIM0_1024_PRESCALER_SELECT

#define TIMER0_NORMAL_MODE 			0
#define TIMER0_PWM_PHASE_CORRECT 	1
#define TIMER0_CTC_MODE				2
#define TIMER0_PWM_FAST				3

#define TIMER0_MODE_SELECT	TIMER0_NORMAL_MODE

#define COMPARE_OUTPUT_DISCONNECTED 0
#define COMPARE_OUTPUT_TOGGLE		1
#define COMPARE_OUTPUT_CLEAR		2
#define COMPARE_OUTPUT_SET			3

#define TIMER0_COMPARE_OUTPUT_SELECT	COMPARE_OUTPUT_DISCONNECTED

#define DISABLED	0
#define	ENABLED		1

#define INT0_OV_INTERRUPT_MODE	ENABLED
#define INT0_OC_INTERRUPT_MODE	DISABLED
#endif /* MCAL_TIMER_TIMER0_CFG_H_ */
