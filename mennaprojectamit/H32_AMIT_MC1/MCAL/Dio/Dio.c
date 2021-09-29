/*
 * Dio.c
 *
 *  Created on: Sep 26, 2020
 *      Author: Mohamed Abdalla
 */
#include "../Dio/Dio.h"
#include "../Dio/Dio_Types.h"
#include "../Dio/Dio_config.h"

DIO_Level Dio_read(Channel_Type channel) {

}


void Dio_write(Channel_Type channel, DIO_Level level) {
	DIO_Port port = channel / 8;
	DIO_Pin pin = channel % 8;

	switch (port) {
	case DIO_PortA:
		if (level == High) {
			SET_BIT(PORTA, pin);
		} else {
			CLR_BIT(PORTA, pin);
		}
		break;
	case DIO_PortB:
		if (level == High) {
			SET_BIT(PORTB, pin);
		} else {
			CLR_BIT(PORTB, pin);
		}
		break;
	case DIO_PortC:
		if (level == High) {
			SET_BIT(PORTC, pin);
		} else {
			CLR_BIT(PORTC, pin);
		}
		break;
	case DIO_PortD:
		if (level == High) {
			SET_BIT(PORTD, pin);
		} else {
			CLR_BIT(PORTD, pin);
		}
		break;
	default:
		break;
	}

}

void Dio_Port_write(DIO_Port port, uint8 data) {

	switch (port) {
	case DIO_PortA:
		PORTA = data;
		break;
	case DIO_PortB:
		PORTB = data;
		break;
	case DIO_PortC:
		PORTC = data;
		break;
	case DIO_PortD:
		PORTD = data;
		break;
	default:
		break;
	}
}
