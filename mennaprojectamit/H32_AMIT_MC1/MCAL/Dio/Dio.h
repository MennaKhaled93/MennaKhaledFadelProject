/*
 * Dio.h
 *
 *  Created on: Sep 26, 2020
 *      Author: Mohamed Abdalla
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include <avr/io.h>
#include "Dio_Types.h"
#include "../../STD_Types.h"
#include "../../Bit_Math.h"

DIO_Level Dio_read(Channel_Type channel);
void Dio_write(Channel_Type channel, DIO_Level level);
void Dio_Port_write(DIO_Port port, uint8 data);

#endif /* MCAL_DIO_DIO_H_ */
