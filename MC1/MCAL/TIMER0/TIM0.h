/*
TIM0.h
*/

#ifndef TIM0_INT_H
#define TIM0_INT_H


#define TIM0_OVF_INT_ENABLE     1
#define TIM0_OVF_INT_DISABLE    0

#define TIM0_CM_INT_ENABLE      1
#define TIM0_CM_INT_DISABLE     0

#define TIM0_CMO_ENABLE      1
#define TIM0_CMO_DISABLE     0


extern void TIM0_init(void);
extern void TIM0_overFlowIntState(unsigned char state);
extern void TIM0_compareMatchIntState(unsigned char state);
extern void TIM0_setTCNT0(unsigned char value);
extern void TIM0_setOCRO(unsigned char value);
void TIM0_forceOutputCompare(unsigned char state);
extern void TIM0_setOvfIntCallback(void (*callbackPtr)(void));
extern void TIM0_setCmIntCallback(void (*callbackPtr)(void));

#endif
