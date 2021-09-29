/*
 * led.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Menna Khaled
 */
#include"../Dio/Dio_Types.h"
#include"../Dio/Dio.h"
#include"../Dio/Dio_config.h"
#include"../../Bit_Math.h"
#include"../../STD_Types.h"
#include"../LED/led.h"


void Led_Handler(uint8 Led )
{
	switch(Led)
	{
		case 0:
			Dio_write(Led0,High);
		break;

		case 1:
			Dio_write(Led1,High);
		break;

		case 2:
			Dio_write(Led2,High);
		break;

		default:
		break;
	}
}


void Led1_Toggle(void)
{
	static uint8 F_State1=0;
	if (1==F_State1)
	{
		Dio_write(Led0,High);
		F_State1=0;
	}
	else
	{
		Dio_write(Led0,Low);
		F_State1=1;
	}
}

void Led2_Toggle(void)
{
	static uint8 F_State2=0;
	if (1==F_State2)
	{
		Dio_write(Led1,High);
		F_State2=0;
	}
	else
	{
		Dio_write(Led1,Low);
		F_State2=1;
	}
}



void Led3_Toggle(void)
{
	static uint8 F_State3=0;
	if (1==F_State3)
	{
		Dio_write(Led2,High);
		F_State3=0;
	}
	else
	{
		Dio_write(Led2,Low);
		F_State3=1;
	}
}

