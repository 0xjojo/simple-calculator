/*
 * Calculator.c
 *
 * Created: 1/17/2023 11:04:17 PM
 * Author : gehad
 */ 


#include "DIO_int.h"
#include "LCD.h"
#include "Keypad.h"
#define F_CPU 16000000
#include <util/delay.h>
void display(u8 x);
u8 res [2] ;
int main(void)
{
	DIO_voidInit();
	LCD_Init();
	KeyPad_Init();
	u8 op = 0,num_1 = 0 , num_2 = 0 , sol = 0;
	
	
	LCD_WriteString("Enter the op");
    while (1) 
    {
		while (!op)
		{
			op = KeyPad_GetValue();
		}
		
		switch(op)
		{
			case '+':
			LCD_Clear();
			LCD_WriteString("Enter the first number");
			LCD_GoTo(1,5);
			while (!num_1)
			{
			num_1 = KeyPad_GetValue();
			}
			LCD_WriteData(num_1);
			num_1 = num_1 - 48;
			_delay_ms(100);
			LCD_Clear();
			LCD_WriteString("Enter the second number");
			while (!num_2)
			{
				num_2 = KeyPad_GetValue();
			}
			LCD_GoTo(1,5);
			LCD_WriteData(num_2);
			num_2 = num_2 - 48;
			_delay_ms(100);
			LCD_Clear();
			sol = num_1 + num_2;
			
			LCD_WriteString("The sum is:");
			
			LCD_GoTo(1,5);
			display(sol);
			
			_delay_ms(400);
			break; 
			///////////////////////////////////////////////////////////////////////////////
			case '*':
			LCD_Clear();
			LCD_WriteString("Enter the first number");
			LCD_GoTo(1,5);
			while (!num_1)
			{
				num_1 = KeyPad_GetValue();
			}
			LCD_WriteData(num_1);
			num_1 = num_1 - 48;
			_delay_ms(100);
			LCD_Clear();
			LCD_WriteString("Enter the second number");
			while (!num_2)
			{
				num_2 = KeyPad_GetValue();
			}
			LCD_GoTo(1,5);
			LCD_WriteData(num_2);
			num_2 = num_2 - 48;
			_delay_ms(100);
			LCD_Clear();
			sol = num_1 * num_2;
			
			LCD_WriteString("The mul is:");
			
			LCD_GoTo(1,5);
			display(sol);
			
			_delay_ms(400);
			break;
			/////////////////////////////////////////////////////////////////////////////
			case '-':
			LCD_Clear();
			LCD_WriteString("Enter the first number");
			LCD_GoTo(1,5);
			while (!num_1)
			{
				num_1 = KeyPad_GetValue();
			}
			LCD_WriteData(num_1);
			num_1 = num_1 - 48;
			_delay_ms(100);
			LCD_Clear();
			LCD_WriteString("Enter the second number");
			while (!num_2)
			{
				num_2 = KeyPad_GetValue();
			}
			LCD_GoTo(1,5);
			LCD_WriteData(num_2);
			num_2 = num_2 - 48;
			_delay_ms(100);
			LCD_Clear();
			if (num_1>num_2)
			{
				sol = num_1 - num_2;
			}
			
			else 
			{
				sol = num_2 - num_1;
			}
			LCD_WriteString("The dif is:");
			LCD_GoTo(1,5);
			display(sol);
			
			_delay_ms(400);
			break;
			//////////////////////////////////////////////////////////////////////////////////
			case '/':
			LCD_Clear();
			LCD_WriteString("Enter the first number");
			LCD_GoTo(1,5);
			while (!num_1)
			{
				num_1 = KeyPad_GetValue();
			}
			LCD_WriteData(num_1);
			num_1 = num_1 - 48;
			_delay_ms(100);
			LCD_Clear();
			LCD_WriteString("Enter the second number");
			while (!num_2)
			{
				num_2 = KeyPad_GetValue();
			}
			LCD_GoTo(1,5);
			LCD_WriteData(num_2);
			num_2 = num_2 - 48;
			_delay_ms(100);
			LCD_Clear();
			if (num_1>num_2)
			{
				sol = num_1 / num_2;
			}
			
			else
			{
				sol = num_2 / num_1;
			}
			LCD_WriteString("The div is:");
			LCD_GoTo(1,5);
			display(sol);
			
			_delay_ms(400);
			break;
			////////////////////////////////////////////////////////////////////////////////////////
			default :
			LCD_Clear();
			LCD_WriteString("In valid op");
			_delay_ms(400);
			break;
			
		}
		LCD_Clear();
		LCD_WriteString("Enter the op");
		op = 0,num_1 = 0 , num_2 = 0 , sol = 0;
		continue;
		
		
		
		
    }
}

void display(u8 x)
{
	if (x > 9)
	{
		res[0] = x%10 +48;
		
		x = x / 10;
		res[1] = x%10 + 48;
		LCD_WriteData(res[1]);
		LCD_WriteData(res[0]);
	}
	else 
	{
		x = x + 48;
		LCD_WriteData(x);
	}
}