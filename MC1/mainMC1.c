#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#include "MCAL/Dio/Dio.h"
#include "MCAL/Dio/Dio_config.h"
#include"MCAL/Dio/Dio_Types.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include "HAL/LCD/lcd.h"
#include "MCAL/External_Interrupt/External_Interrupt.h"
#include "MCAL/External_Interrupt/Interrupt_config.h"
#include "MCAL/ADC/adc.h"
#include "MCAL/ADC/adc_cfg.h"
#include "MCAL/Timer/timer0.h"
#include "MCAL/Timer/timer0_cfg.h"
#include "MCAL/TIMER0/TIM0.h"
#include "MCAL/TIMER0/TIM0_cfg.h"
#include"MCAL/SPI/spi.h"
#include"MCAL/UART/UART.h"


int main(void)
{
	uint8 x=0;
    Dio_init();
    lcd_init();
    lcd_clear();
	SPI_initMaster(); // Master Initialization
	_delay_ms(50); // delay until MC2 finish its initialization task
	UART_init();
    while(1)
    {
    	x= UART_recieveByte();
        lcd_str(&x);
        SPI_sendByte(x);

    }
}
