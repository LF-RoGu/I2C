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

static uint8 key_flag = FALSE,
			 enter_flag = FALSE,
			 esc_flag = FALSE,
			 state_flag = FALSE;
static uint8 past_state = FALSE;

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
	return (temp1 + ASCII_CONV);
}
uint8 get_centena()
{
	return (temp2 + ASCII_CONV);
}
uint8 get_millar()
{
	return (temp3 + ASCII_CONV);
}
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION*/
void set_past_state(uint8 state)
{
	past_state = state;
}
uint8 get_past_state()
{
	return past_state;
}
void (*ptr_funct[PTR_SIZE])() =
{
		TERA_menu,
		show_set_hour,
		show_set_date,
		get_hour,
		get_date,
		write_mem
};
void fptr_function(uint8 funct)
{
	if((LOW_LIMIT <= funct) || (HIGH_LIMIT >= funct))
	{
		(*ptr_funct[funct])();
	}
}
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION*/
void set_state()
{
	if(((ASCII_ESC == key_flag) && (state_flag != MENU)) || (RETURN == state_flag))
	{
		state_flag = MENU;
		set_past_state(get_past_state());
		fptr_function(state_flag);
		enter_flag = FALSE;
	}
	if(MENU == state_flag)
	{
			if ((ASCII_NUMBER_1 == key_flag) && (TRUE == enter_flag)) {
				state_flag = SET_HOUR;
				fptr_function(state_flag);
				enter_flag = FALSE;
			}
			if ((ASCII_NUMBER_2 == key_flag) && (TRUE == enter_flag)) {
				state_flag = SET_DATE;
				fptr_function(state_flag);
				enter_flag = FALSE;
			}
			if ((ASCII_NUMBER_3 == key_flag) && (TRUE == enter_flag)) {
				state_flag = READ_HOUR;
				fptr_function(state_flag);
				enter_flag = FALSE;
			}
			if ((ASCII_NUMBER_4 == key_flag) && (TRUE == enter_flag)) {
				state_flag = READ_DATE;
				fptr_function(state_flag);
				enter_flag = FALSE;
			}
			if ((ASCII_NUMBER_5 == key_flag) && (TRUE == enter_flag)) {
				state_flag = WRITE_MEM;
				fptr_function(state_flag);
				enter_flag = FALSE;
			}
			if ((ASCII_NUMBER_6 == key_flag) && (TRUE == enter_flag)) {
				state_flag = SHOW_MEM;
				fptr_function(state_flag);
				enter_flag = FALSE;
			}
	}
		if (SET_HOUR == state_flag) {
			change_hour();
		}
		if (SET_DATE == state_flag) {
			change_date();
		}
		if (READ_HOUR == state_flag) {
			get_hour();
		}
		if (READ_DATE == state_flag) {
			get_date();
		}
		if (WRITE_MEM == state_flag) {

		}
		if (SHOW_MEM == state_flag) {

		}
}

void set_key(uint8 key)
{
	key_flag = key;
}
uint8 get_key()
{
	return key_flag;
}
void set_enter(uint8 enter)
{
	enter_flag = enter;
}
uint8 get_enter()
{
	return enter_flag;
}
void set_esc(uint8 esc)
{
	esc_flag = esc;
}
uint8 get_esc()
{
	return esc_flag;
}
void set_st(uint8 state)
{
	state_flag = state;
}
uint8 get_st()
{
	return state_flag;
}
