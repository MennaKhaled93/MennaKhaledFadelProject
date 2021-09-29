/*
 * spi.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Menna Khaled
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include"avr/io.h"
#include"util/delay.h"
#include"../External_Interrupt/External_Interrupt.h"
#include "../../Bit_Math.h"
#include "../../STD_Types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_sendByte(const uint8 data);
uint8 SPI_recieveByte(void);
void SPI_sendString(const uint8 *Str);
void SPI_receiveString(char *Str);



#endif /* MCAL_SPI_SPI_H_ */
