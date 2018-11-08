/*
 * UART_DECO.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include "UART_DECO.h"

static uint8 temp0 = FALSE,	/*Unidad*/
			 temp1 = FALSE,	/*Decena*/
			 temp2 = FALSE,	/*Centena*/
			 temp3 = FALSE,	/*Millar*/
			 temp4 = FALSE; /*Decena Millar*/

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION TO DECO THE VALUE OBTAINED FROM THE MEMORY*/

void value_capture(uint32 value)
{
	uint8 tempValue4 = value / DECENA_MILLAR;
	uint8 tempValue3 = value / MILLAR;
	uint8 tempValue2 = value / CENTENA;
	uint8 tempValue1 = value / DECENA;

	/*Decena del Millar*/
	if (FALSE != tempValue4)
		temp4 = tempValue4;
	else
		temp4 = 0;
	/*Millar*/
	if (FALSE != tempValue3) {
		value = value - (DECENA_MILLAR * temp4);
		temp3 = value / MILLAR;
	} else
		temp3 = 0;
	/*Centena*/
	if (FALSE != tempValue2) {
		value = value - (MILLAR * temp3);
		temp2 = value / CENTENA;
	} else
		temp2 = 0;
	/*Decena*/
	if (FALSE != tempValue1) {
		value = value - (CENTENA * temp2);
		temp1 = value / DECENA;
	} else
		temp1 = 0;
	/*Unidad*/
	if (FALSE != value)
		temp0 = value - (DECENA * temp1);
	else
		temp0 = 0;
}

uint8 get_unidad()
{
	return (temp0 + ASCII_CONV);
}
uint8 get_decena()
{
	return (temp4 + ASCII_CONV);
}
uint8 get_centena()
{
	return (temp3 + ASCII_CONV);
}
uint8 get_millar()
{
	return (temp2 + ASCII_CONV);
}
uint8 get_decenaMillar()
{
	return (temp1 + ASCII_CONV);
}
