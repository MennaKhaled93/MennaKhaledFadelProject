/*
 * Dio.h

 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include"../Dio/Dio_Types.h"
#include"../Dio/Dio_config.h"
#include<util/delay.h>
#include "../../STD_Types.h"
#include "../../Bit_Math.h"
void Dio_init(void);
DIO_Level Dio_read(Channel_Type channel);
void Dio_write(Channel_Type channel, DIO_Level level);
void Dio_Port_write(DIO_Port port, uint8 data);

#endif /* MCAL_DIO_DIO_H_ */
