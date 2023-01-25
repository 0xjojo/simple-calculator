/*
 * LCD.h
 *
 * Created: 1/4/2023 9:36:03 PM
 *  Author: gehad
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"

void LCD_Init (void);

void LCD_WriteCommand(u8 cmd);

void LCD_WriteData(u8 data);

void LCD_GoTo(u8 row,u8 col);

void LCD_WriteString(u8* str);

void LCD_Clear(void);



#endif /* LCD_H_ */