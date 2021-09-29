/*
 * Dio_config.h

 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

#include <avr/io.h>
#include "Dio_Types.h"
#include "../../Bit_Math.h"
#include "../../STD_Types.h"
//#include ""
#define PIN_COUNT 4

typedef struct{
	DIO_Port PinPort;
	DIO_Pin Pin;
	DIO_Dir PinDir;
	DIO_Level PinLevel;
}DIO_PinCfg;

void Dio_init(void);

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
