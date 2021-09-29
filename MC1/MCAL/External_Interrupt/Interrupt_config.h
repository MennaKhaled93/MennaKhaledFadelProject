/*
 * Interrupt_config.h

 */

#ifndef MCAL_EXTERNAL_INTERRUPT_INTERRUPT_CONFIG_H_
#define MCAL_EXTERNAL_INTERRUPT_INTERRUPT_CONFIG_H_

#define DISABLED 	0
#define ENABLED		1

#define EXTI_INT0	ENABLED
#define EXTI_INT1	DISABLED
#define EXTI_INT2	DISABLED

#define Low_Level 		0
#define Both_Edges		1
#define Falling_Edge	2
#define Raising_Edge	3

#define EXTI_INT0_EDGE	Both_Edges
#define EXTI_INT1_EDGE	Both_Edges
#define EXTI_INT2_EDGE	Both_Edges

#endif /* MCAL_EXTERNAL_INTERRUPT_INTERRUPT_CONFIG_H_ */
