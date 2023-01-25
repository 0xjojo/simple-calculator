/*
 * Keypad.c
 *
 * Created: 1/11/2023 12:39:55 PM
 *  Author: gehad
 */ 
#include "Keypad.h"
#include "Keypad_Cfg.h"
#define F_CPU 16000000
#include "util/delay.h"

#define COL_INIT    24
#define COL_FINAL   27

#define ROW_INIT    28
#define ROW_FINAL   31

const u8 KeyPad_Values[4][4] = {  {'7' , '8' , '9' , '/'},
                                  {'4' , '5' , '6' , '*'},
								  {'1' , '2' , '3' , '-'},
								  {'c' , '0' , '=' , '+'} };

void KeyPad_Init(void)
{
	DIO_voidSetPinValue(KEYPAD_COL0,DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_COL1,DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_COL2,DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_COL3,DIO_U8_HIGH);
	
	DIO_voidSetPullUp(KEYPAD_ROW0);
	DIO_voidSetPullUp(KEYPAD_ROW1);
	DIO_voidSetPullUp(KEYPAD_ROW2);
	DIO_voidSetPullUp(KEYPAD_ROW3);
}


u8 KeyPad_GetValue(void)
{
	u8 LOC_Col = 0;
	u8 LOC_Row = 0;
	u8 Value   = 0;
	u8 Temp    = 0;
	
	for (LOC_Col = COL_INIT; LOC_Col <= COL_FINAL ; LOC_Col++ )
	{
		DIO_voidSetPinValue(LOC_Col,DIO_U8_LOW);
		for(LOC_Row = ROW_INIT; LOC_Row <= ROW_FINAL ; LOC_Row++ )
		{
			Temp = DIO_u8GetPinValue(LOC_Row);
			if (!Temp) 
			{
				Value =  KeyPad_Values[LOC_Row - ROW_INIT][LOC_Col - COL_INIT]; 
				while (!Temp)
				{
					Temp = DIO_u8GetPinValue(LOC_Row);
				}
				_delay_ms(10);
			}
		}
		DIO_voidSetPinValue(LOC_Col,DIO_U8_HIGH);
	}
	return Value; 
}