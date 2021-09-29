/*
 * timer0.h

 */

#ifndef MCAL_TIMER_TIMER0_H_
#define MCAL_TIMER_TIMER0_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../Bit_Math.h"
#include "../../STD_Types.h"
#include "timer0_cfg.h"

void timer0_init();
void setCallback_T0_TOV(void(*p2f)());
void setCallback_T0_OCF(void(*p2f)());

#endif /* MCAL_TIMER_TIMER0_H_ */
