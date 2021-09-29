/*
 * adc.h

 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include <avr/io.h>
#include "../../Bit_Math.h"
#include "../../STD_Types.h"

void adc_init(void);
uint16 adc_read(uint8 channel);

#endif /* MCAL_ADC_ADC_H_ */
