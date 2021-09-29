/*
 * timer0.h

 */

#ifndef MCAL_TIMER_TIMER0_H_
#define MCAL_TIMER_TIMER0_H_
#include"../External_Interrupt/External_Interrupt.h"
#include"../External_Interrupt/Interrupt_config.h"

#include <avr/interrupt.h>
#include "../Timer/timer0_cfg.h"

void timer0_init();
void setCallback_T0_TOV(void(*p2f)());
void setCallback_T0_OCF(void(*p2f)());

#endif /* MCAL_TIMER_TIMER0_H_ */
