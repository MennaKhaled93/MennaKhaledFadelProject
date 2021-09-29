/*
 * lcd.h
 *
 *  Created on: Jul 31, 2021
 *      Author: Mohamed Abdulaal
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include<avr/io.h>
#define UPPER_PORT_PINS
#include "../../STD_Types.h"
#include "../../Bit_Math.h"
#include "../../MCAL/Dio/Dio.h"
#include <util/delay.h>

void lcd_init();
void lcd_command(uint8 cmd);
void lcd_char(uint8 data);
void lcd_clear();
void lcd_str(uint8 *str);
void lcd_str_xy(uint8 x, uint8 y,uint8 *str);
#endif /* HAL_LCD_LCD_H_ */
