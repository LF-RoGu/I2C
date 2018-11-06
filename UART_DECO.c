/*
 * UART_DECO.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include "UART_DECO.h"

static uint8 temp0,	/*Unidad*/
			 temp1,	/*Decena*/
			 temp2,	/*Centena*/
			 temp3,	/*Millar*/
			 temp4; /*Decena Millar*/

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION TO DECO THE VALUE OBTAINED FROM THE MEMORY*/

void valueCapture(uint32 value)
{
	uint8 tempValue1 = value / DECENA_MILLAR;
	uint8 tempValue2 = value / MILLAR;
	uint8 tempValue3 = value / CENTENA;
	uint8 tempValue4 = value / DECENA;

	/*Decena del Millar*/
	if (FALSE != tempValue1)
		temp1 = tempValue1;
	else
		temp1 = 0;
	/*Millar*/
	if (FALSE != tempValue2) {
		value = value - (DECENA_MILLAR * temp1);
		temp2 = value / MILLAR;
	} else
		temp2 = 0;
	/*Centena*/
	if (FALSE != tempValue3) {
		value = value - (MILLAR * temp2);
		temp3 = value / CENTENA;
	} else
		temp3 = 0;
	/*Decena*/
	if (FALSE != tempValue4) {
		value = value - (CENTENA * temp3);
		temp4 = value / DECENA;
	} else
		temp4 = 0;
	/*Unidad*/
	if (FALSE != value)
		temp0 = value - (DECENA * temp4);
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
