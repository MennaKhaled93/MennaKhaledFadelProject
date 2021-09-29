/*
 * adc_cfg.h

 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

#define ENABLE 	1
#define DISABLE	0

#define ADC_ENABLE	ENABLE

#define ADC_SOURCE_INTERNAL	0
#define	ADC_SOURCE_AVCC		1
#define ADC_SOURCE_RESERVED	2
#define ADC_SOURCE_VREF		3	// 2.56v

#define ADC_SOURCE	ADC_SOURCE_VREF

#define ADC_PRESCALER_2		0
#define ADC_PRESCALER_4 	1
#define ADC_PRESCALER_8 	2
#define ADC_PRESCALER_16	3
#define ADC_PRESCALER_32	4
#define ADC_PRESCALER_64	5
#define ADC_PRESCALER_128	6

#define ADC_PRESCALER_MODE	ADC_PRESCALER_128

#endif /* MCAL_ADC_ADC_CFG_H_ */
