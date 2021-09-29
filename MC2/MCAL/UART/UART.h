/*
 * UART.h
 *
 *  Created on: Sep 28, 2021
 *      Author: Menna Khaled
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../Bit_Math.h"
#include "../../STD_Types.h"
#include"avr/io.h"
#include"util/delay.h"
#include"../External_Interrupt/External_Interrupt.h"
#include"../External_Interrupt/Interrupt_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(void);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str); // Receive until #

#endif /* MCAL_UART_UART_H_ */
