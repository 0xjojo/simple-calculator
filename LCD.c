/*
 * LCD.c
 *
 * Created: 1/4/2023 9:35:37 PM
 *  Author: gehad
 */ 
#include "DIO_int.h"
#include "DIO_private.h"
#include "LCD.h"

#define F_CPU 16000000
#include <util/delay.h>

void LCD_Init (void)
{
	#if LCD_MODE == 8
	
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0E);
	LCD_WriteCommand(0x01);
	
	_delay_ms(5);
	
	#elif LCD_MODE == 4
	
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
	#endif
}

void LCD_WriteCommand(u8 cmd)
{
	DIO_voidSetPinValue(LCD_U8_RS,DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_RW,DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	PORTA = (cmd & 0xF0) | (PORTA & 0x0F);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	
	PORTA = (cmd << 4)|(PORTA & 0x0F); 
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	_delay_ms(5);	

}

void LCD_WriteData(u8 data)
{
	DIO_voidSetPinValue(LCD_U8_RS,DIO_U8_HIGH);
	DIO_voidSetPinValue(LCD_U8_RW,DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	PORTA = (data & 0xF0) | (PORTA & 0x0F);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	
	PORTA = (data << 4)|(PORTA & 0x0F);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	_delay_ms(5);
}

void LCD_GoTo(u8 row,u8 col)
{
	u8 pos[2] = {0x80,0xC0};
	LCD_WriteCommand(pos[row]+col);
}

void LCD_WriteString(u8* str)
{
	u8 i = 0;
	
	while (str[i] != '\0')
	{
		LCD_WriteData(str[i]);
		i++;
	}
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

