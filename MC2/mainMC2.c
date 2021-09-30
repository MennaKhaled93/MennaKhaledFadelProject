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

volatile int ctr = 0;
volatile int ctr2 = 0;

void test(void){
	ctr++;
}

void TIM0_init2(void){
	TCNT0 = 0;
	// Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	// Prescaler
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);


}




//void PWM_init()
//{
	/*set fast PWM mode with non-inverted output*/
//	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS02);
//	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
//}


//int main ()
//{
	//unsigned char duty;

//	PWM_init();
//	while (1)
	//{
		//for(duty=0; duty<255; duty++)
		//{
			//OCR0=duty;  /*increase the LED light intensity*/
//			_delay_ms(8);
//		}
//		for(duty=255; duty>1; duty--)
//		{
//			OCR0=duty;  /*decrease the LED light intensity*/
//			_delay_ms(8);
//		}
//	}
//}


//void ssd_same(uint8 cmd){
	//SET_BIT(PORTB,1);// enable SSD1
	//SET_BIT(PORTB,2);// enable SSD2
//	SET_BIT(PORTB,3);// enable decimal point

	//if (GET_BIT(cmd,0)){
		//SET_BIT(PORTA,4);
//	}else {
	//	CLR_BIT(PORTA,4);
	//}

	//if (GET_BIT(cmd,1)){
		//SET_BIT(PORTA,5);
	//}else {
		//CLR_BIT(PORTA,5);
	//}

	//if (GET_BIT(cmd,2)){
		//SET_BIT(PORTA,6);
	//}else {
		//CLR_BIT(PORTA,6);
	//}

	//if (GET_BIT(cmd,3)){
		//SET_BIT(PORTA,7);
	//}else {
		//CLR_BIT(PORTA,7);
	//}

//}


//void ssd_different(uint8 cmd1, uint8 cmd2){
//	SET_BIT(PORTB,1);// enable SSD1
	//CLR_BIT(PORTB,2);// disable SSD2
	//SET_BIT(PORTB,3);// enable decimal point

//	if (GET_BIT(cmd1,0)){
//		SET_BIT(PORTA,4);
//	}else {
//		CLR_BIT(PORTA,4);
//	}

//	if (GET_BIT(cmd1,1)){
//		SET_BIT(PORTA,5);
//	}else {
//		CLR_BIT(PORTA,5);
//	}

//	if (GET_BIT(cmd1,2)){
//		SET_BIT(PORTA,6);
//	}else {
//		CLR_BIT(PORTA,6);
	//}

//	if (GET_BIT(cmd1,3)){
//		SET_BIT(PORTA,7);
//	}else {
//		CLR_BIT(PORTA,7);
//	}
//	_delay_ms(5);
//	CLR_BIT(PORTB,1);// disable SSD1
//	SET_BIT(PORTB,2);// enable SSD2

//	if (GET_BIT(cmd2,0)){
//		SET_BIT(PORTA,4);
//	}else {
//		CLR_BIT(PORTA,4);
//	}

//	if (GET_BIT(cmd2,1)){
//		SET_BIT(PORTA,5);
//	}else {
		//CLR_BIT(PORTA,5);
	//}

//	if (GET_BIT(cmd2,2)){
//		SET_BIT(PORTA,6);
//	}else {
	//	CLR_BIT(PORTA,6);
//	}

//	if (GET_BIT(cmd2,3)){
//		SET_BIT(PORTA,7);
//	}else {
//		CLR_BIT(PORTA,7);
//	}
	//_delay_ms(5);
//}

//int main(){


	//Dio_init();// set ports PB1,PB2,PB3,PA4,PA5,PA6,PA7 to output using DDRB and DRRA

	//uint8 x = 0;
//uint8 y =0;

		//while(1){
			//ssd_same(x);
			//ssd_different(x,y);
		//	if(x>8){
				//x=0;
			//	if(y>8){
				//	y=0;
			//	}else {
		//		y++;}

	//		}else {
				//x++;
			//}
		//	_delay_ms(150);
	//	}
//}




/*

int main(void)
{
    Dio_init();
	SPI_initMaster(); // Master Initialization
	_delay_ms(50); // delay until MC2 finish its initialization task
	SPI_SendString("I am menna");
    while(1)
    {

    }
}

int main(void)
{
	Dio_init();
	lcd_init();
	lcd_clear();
	lcd_str("MENNA");

   while(1){ }
}


*/


int main()
{
	uint8 y=0;
    Dio_init();
	SPI_initSlave();

	while(1)
	{
		y= SPI_recieveByte();

		if(y=='0')
		{
			TOGGLE_BIT(PORTC,2);
		}

		else if(y=='1')
		{
			TOGGLE_BIT(PORTC,7);
		}
		else if(y=='2')
		{
			TOGGLE_BIT(PORTD,3);
		}
	}
}
