/*
 * Dio_Types.h
 *
 *  Created on: Sep 26, 2020
 *      Author: Mohamed Abdalla
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

typedef enum{
	// Port A
	PINA_0,
	PINA_1,
	Relay,
	Buzzer,
	D4,
	D5,
	D6,
	D7,

	// Port B
	Button0,
	RS,
	RW, Slave1= 10,
	E, Slave2 = 11,
	Button1,
	PINB_5,
	PINB_6,
	PINB_7,

	// Port C
	PINC_0,
	PINC_1,
	Led0,
	HBr_1,
	HBr_2,
	HBr_3,
	HBr_4,
	Led1,

	// Port D
	PIND_0,
	PIND_1,
	Button2,
	Led2,
	HBr_E1,
	HBr_E2,
	PIND_6,
	PIND_7
}Channel_Type;


typedef enum{
	DIO_Pin0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7
}DIO_Pin;

typedef enum{
	DIO_PortA,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
}DIO_Port;

typedef enum{
	Low,
	High
}DIO_Level;

typedef enum{
	Input,
	Output
}DIO_Dir;

#endif /* MCAL_DIO_DIO_TYPES_H_ */
