/*
 * bluetooth.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Menna Khaled
 */
#include"../Bluetooth/bluetooth.h"
#include"../../MCAL/Dio/Dio.h"
#include"../../MCAL/Dio/Dio_Types.h"
#include"../../MCAL/Dio/Dio_config.h"


#include"../../MCAL/UART/UART.h"
#include"../../Bit_Math.h"
#include"../../STD_Types.h"


void bluetooth (uint8 text)
{
	UART_init();
	UART_sendString(text);
}
