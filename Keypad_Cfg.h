/*
 * Keypad_Cfg.h
 *
 * Created: 1/9/2023 10:30:56 PM
 *  Author: gehad
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO_int.h"
#include "DIO_private.h"

#define KEYPAD_PORT   PORTD

#define  KEYPAD_COL0   DIO_U8_PIN24
#define  KEYPAD_COL1   DIO_U8_PIN25
#define  KEYPAD_COL2   DIO_U8_PIN26
#define  KEYPAD_COL3   DIO_U8_PIN27
	    
#define  KEYPAD_ROW0   DIO_U8_PIN28
#define  KEYPAD_ROW1   DIO_U8_PIN29
#define  KEYPAD_ROW2   DIO_U8_PIN30
#define  KEYPAD_ROW3   DIO_U8_PIN31





#endif /* KEYPAD_CFG_H_ */