/*
 * UART_DECO.h
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#ifndef UART_DECO_H_
#define UART_DECO_H_

#include "Bits.h"
#include "MK64F12.h"

#define DECENA 10
#define CENTENA 100
#define MILLAR 1000

typedef enum {
	ASCII_NUMBER_0 = 48,
	ASCII_NUMBER_1 = 49,
	ASCII_NUMBER_2 = 50,
	ASCII_NUMBER_3 = 51,
	ASCII_NUMBER_4 = 52,
	ASCII_NUMBER_5 = 53,
	ASCII_NUMBER_6 = 54,
	ASCII_NUMBER_7 = 55,
	ASCII_NUMBER_8 = 56,
	ASCII_NUMBER_9 = 57,
	ASCII_NUMBER_10 = 50,
	ASCII_ENTER = 13,
	ASCII_ESC = 27
}Deco_type;

typedef enum {
	SETHOUR,
	SETDATE,
	READHOUR,
	READDATE,
	RETURN
}Time_type;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct to set a certain state depending on wich key is pressed
 	 \param[in]  void
 	 \return void
 */
void set_menu();

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION TO DECO THE VALUE OBTAINED FROM THE MEMORY*/
/*!
 	 \brief	Funct to get the units form a hole value
 	 \param[in] value
 	 \return void
 */
uint8 valueCapture(uint32 value);

#endif /* UART_DECO_H_ */
