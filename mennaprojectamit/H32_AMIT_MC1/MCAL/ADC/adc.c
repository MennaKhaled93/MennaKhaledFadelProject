/*
 * adc.c
 *
 *  Created on: Oct 9, 2020
 *      Author: Mohamed Abdalla
 */
#include "../ADC/adc.h"
#include "../ADC/adc_cfg.h"

void adc_init(void){
	// Enable ADC
#if ADC_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADEN);
#endif
	/*
	ADC_SOURCE_INTERNAL
	ADC_SOURCE_AVCC
	ADC_SOURCE_RESERVED
	ADC_SOURCE_VREF
	 */
#if ADC_SOURCE == ADC_SOURCE_INTERNAL
	// Selection for the power source
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
#elif ADC_SOURCE == ADC_SOURCE_AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
#elif ADC_SOURCE == ADC_SOURCE_VREF
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
#endif

#if ADC_PRESCALER_MODE == ADC_PRESCALER_2
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	/*
	TODO:
	*/
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_128

	// Set Prescaler division factor fclk/128
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#endif
}

uint16 adc_read(uint8 channel){
	ADMUX = (ADMUX & 0b11100000) | channel;

	SET_BIT(ADCSRA,ADSC);	//Start conversion
	while(GET_BIT(ADCSRA,ADIF)== 0); // Wait for conversion to finish
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
