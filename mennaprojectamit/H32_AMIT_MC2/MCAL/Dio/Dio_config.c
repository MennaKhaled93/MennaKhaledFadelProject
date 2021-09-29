/*
 * Dio_config.c
 *
 *  Created on: Sep 26, 2020
 *      Author: Mohamed Abdalla
 */
#include"../Dio/Dio.h"
#include "../Dio/Dio_config.h"


DIO_PinCfg Pin_Cfgs[]={
		/* PORTA */
		{DIO_PortA, DIO_Pin0, Input, Low},
		{DIO_PortA, DIO_Pin1, Input, Low},
		{DIO_PortA, DIO_Pin2, Output, Low},
		{DIO_PortA, DIO_Pin3, Output, Low},
		{DIO_PortA, DIO_Pin4, Output, Low},
		{DIO_PortA, DIO_Pin5, Output, Low},
		{DIO_PortA, DIO_Pin6, Output, Low},
		{DIO_PortA, DIO_Pin7, Output, Low},
		/* PORTB */
		{DIO_PortB, DIO_Pin1, Output, Low},
		{DIO_PortB, DIO_Pin2, Output, Low},
		{DIO_PortB, DIO_Pin3, Output, Low},
		{DIO_PortB, DIO_Pin4, Input, Low},
		{DIO_PortB, DIO_Pin5, Input, Low},
		{DIO_PortB, DIO_Pin6, Output, Low},
		{DIO_PortB, DIO_Pin7, Input, Low},
		/* PORTC */
		{DIO_PortC, DIO_Pin2, Output, Low},
		{DIO_PortC, DIO_Pin3, Output, Low},
		{DIO_PortC, DIO_Pin4, Output, Low},
		{DIO_PortC, DIO_Pin5, Output, Low},
		{DIO_PortC, DIO_Pin6, Output, Low},
		{DIO_PortC, DIO_Pin7, Output, Low},
		/* PORTD */
		{DIO_PortD, DIO_Pin3, Output, Low},
		{DIO_PortD, DIO_Pin4, Output, Low},
		{DIO_PortD, DIO_Pin5, Output, Low}
};

void Dio_init(void){
	int count = sizeof(Pin_Cfgs)/ sizeof(Pin_Cfgs[0]);
	int i = 0;
	for(i = 0; i < count ; i++){
		if(Pin_Cfgs[i].PinPort == DIO_PortA){ //DDRA
			if(Pin_Cfgs[i].PinDir == Output){
				SET_BIT(DDRA,Pin_Cfgs[i].Pin);
			}
			else{
				CLR_BIT(DDRA,Pin_Cfgs[i].Pin);
			}
		}
		else if(Pin_Cfgs[i].PinPort == DIO_PortB){ //DDRB
			if(Pin_Cfgs[i].PinDir == Output){
				SET_BIT(DDRB,Pin_Cfgs[i].Pin);
			}
			else{
				CLR_BIT(DDRB,Pin_Cfgs[i].Pin);
			}
		}
		else if(Pin_Cfgs[i].PinPort == DIO_PortC){ //DDRC
			if(Pin_Cfgs[i].PinDir == Output){
				SET_BIT(DDRC,Pin_Cfgs[i].Pin);
			}
			else{
				CLR_BIT(DDRC,Pin_Cfgs[i].Pin);
			}
		}
		else if(Pin_Cfgs[i].PinPort == DIO_PortD){ //DDRD
			if(Pin_Cfgs[i].PinDir == Output){
				SET_BIT(DDRD,Pin_Cfgs[i].Pin);
			}
			else{
				CLR_BIT(DDRD,Pin_Cfgs[i].Pin);
			}
		}
	}
}

