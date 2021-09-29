/*
 * lcd.c

 */
#include "../LCD/lcd.h"
#include "../../MCAL/Dio/Dio.h"
#include "../../MCAL/Dio/Dio_Types.h"
#include "../../MCAL/Dio/Dio_config.h"


void lcd_command(uint8 cmd){

	Dio_write(RS,Low);
	Dio_write(RW,Low);
	//DIO_Write(lcd_en,low);

	GET_BIT(cmd,7)?Dio_write(D7,High):Dio_write(D7,Low);
	GET_BIT(cmd,6)?Dio_write(D6,High):Dio_write(D6,Low);
	GET_BIT(cmd,5)?Dio_write(D5,High):Dio_write(D5,Low);
	GET_BIT(cmd,4)?Dio_write(D4,High):Dio_write(D4,Low);
	Dio_write(E,High);
	_delay_us(10);
	Dio_write(E,Low);
	_delay_us(200);

	GET_BIT(cmd,3)?Dio_write(D7,High):Dio_write(D7,Low);
	GET_BIT(cmd,2)?Dio_write(D6,High):Dio_write(D6,Low);
	GET_BIT(cmd,1)?Dio_write(D5,High):Dio_write(D5,Low);
	GET_BIT(cmd,0)?Dio_write(D4,High):Dio_write(D4,Low);
	Dio_write(E,High);
	_delay_us(10);
	Dio_write(E,Low);
	_delay_us(200);
}

void lcd_init(){
	//DDRA = 0xff;			// set port direction as output
	Dio_write(RW,Low);
	_delay_ms(20);
	lcd_command(0x33);
	lcd_command(0x32);
	lcd_command(0x28);
	lcd_command(0x0f);
	lcd_command(0x06);
	lcd_command(0x01);
	_delay_ms(20);
}

void lcd_char(uint8 data){

	Dio_write(RS,High);
	Dio_write(RW,Low);
	//DIO_Write(lcd_en,low);

	GET_BIT(data,7)?Dio_write(D7,High):Dio_write(D7,Low);
	GET_BIT(data,6)?Dio_write(D6,High):Dio_write(D6,Low);
	GET_BIT(data,5)?Dio_write(D5,High):Dio_write(D5,Low);
	GET_BIT(data,4)?Dio_write(D4,High):Dio_write(D4,Low);

	Dio_write(E,High);
	_delay_us(10);
	Dio_write(E,Low);
	_delay_us(200);

	GET_BIT(data,3)?Dio_write(D7,High):Dio_write(D7,Low);
	GET_BIT(data,2)?Dio_write(D6,High):Dio_write(D6,Low);
	GET_BIT(data,1)?Dio_write(D5,High):Dio_write(D5,Low);
	GET_BIT(data,0)?Dio_write(D4,High):Dio_write(D4,Low);

	Dio_write(E,High);
	_delay_us(1);
	Dio_write(E,Low);
	_delay_us(200);
}

void lcd_str(uint8 *str){
	int i =0;
	while(str[i]!=0){
		lcd_char(str[i]);
		i++;
	}
}

void lcd_clear(){
	lcd_command(0x01); //clear the display
	_delay_ms(2);
	lcd_command(0x80); //cursor at (0,0)
}

void lcd_str_xy(uint8 x, uint8 y,uint8 *str){
	if (y==0 && x<16){
		lcd_command((x & 0x0f)|0x80);//cursor at the xy cordinates
	}else if(y==1 && x<16){
		lcd_command((x & 0x0f)|0xc0);//cursor at the xy cordinates
	}
	lcd_str(str);
}
