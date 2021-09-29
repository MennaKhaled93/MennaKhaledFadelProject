/*
 * External_Interrupt.h
 *
 *  Created on: Oct 3, 2020
 *      Author: Mohamed Abdalla
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

#include "../External_Interrupt/Interrupt_config.h"

void init_interrupt(void);
void Set_CallBack_INT0(void (*p2func)(void));
void Set_CallBack_INT1(void (*p2func)(void));
void Set_CallBack_INT2(void (*p2func)(void));

#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
