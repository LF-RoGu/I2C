/*
 * UART_DECO.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include "UART_DECO.h"

#define N_PROCESS 8

static uint8 temp0 = FALSE, /*Unidad*/
			 temp1 = FALSE, /*Decena*/
			 temp2 = FALSE, /*Centena*/
			 temp3 = FALSE, /*Millar*/
			 temp4 = FALSE; /*Decena Millar*/

static uint8 key_pressed = FALSE, /*Var to store the key pressed for the terminal*/
			 enter_flag = FALSE,
			 escape_flag = FALSE,
			 state = FALSE;

static uint8 next_state = FALSE,
			 past_state = FALSE;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION TO DECO THE VALUE OBTAINED FROM THE MEMORY*/

void value_capture(uint32 value) {
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

uint8 get_unidad() {
	return (temp0 + ASCII_CONV);
}
uint8 get_decena() {
	return (temp1 + ASCII_CONV);
}
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
void set_state() {
	if (((ASCII_ESC == key_pressed) && MENU != state) || (RETURN == state)) {
		/*set state to menu*/
		state = MENU;
		/*call funct to store past state*/
		set_past_state(get_state());
		/*access the state*/
		access_state(state);
		enter_flag = FALSE;
	}
	if (MENU == state) {
		if ((ASCII_NUMBER_1 == key_pressed) && (TRUE == enter_flag)) {
			state = SET_HOUR;
			/*access the state*/
			access_state(state);
			/*Reset the enter_flag*/
			enter_flag = FALSE;
		}
		if ((ASCII_NUMBER_2 == key_pressed) && (TRUE == enter_flag)) {
			state = SET_DATE;
			/*access the state*/
			access_state(state);
			/*Reset the enter_flag*/
			enter_flag = FALSE;
		}
		if ((ASCII_NUMBER_3 == key_pressed) && (TRUE == enter_flag)) {
			state = READ_HOUR;
			/*access the state*/
			access_state(state);
			/*Reset the enter_flag*/
			enter_flag = FALSE;
		}
		if ((ASCII_NUMBER_4 == key_pressed) && (TRUE == enter_flag)) {
			state = READ_DATE;
			/*access the state*/
			access_state(state);
			/*Reset the enter_flag*/
			enter_flag = FALSE;
		}
		if ((ASCII_NUMBER_5 == key_pressed) && (TRUE == enter_flag)) {
			state = WRITE_MEM;
			/*access the state*/
			access_state(state);
			/*Reset the enter_flag*/
			enter_flag = FALSE;
		}
		if ((ASCII_NUMBER_6 == key_pressed) && (TRUE == enter_flag)) {
			state = SHOW_MEM;
			/*access the state*/
			access_state(state);
			/*Reset the enter_flag*/
			enter_flag = FALSE;
		}
	}
	if (SET_HOUR == state) {

	}
	if (SET_DATE == state) {

	}
	if (READ_HOUR == state) {
		get_hour();
	}
	if (READ_DATE == state) {
		get_date();
	}
	if (WRITE_MEM == state) {

	}
	if (SHOW_MEM == state) {

	}
}

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION SAVE THE FLAGS IN THE GLOBAL VARIABLES*/
void set_key(uint8 key)
{
	key_pressed = key;
}
uint8 get_key()
{
	return key_pressed;
}
void set_enter(uint8 enter)
{
	enter_flag = enter;
}
uint8 get_enter()
{
	return enter_flag;
}
void set_escape(uint8 escape)
{
	escape_flag = escape;
}
uint8 get_escape()
{
	return escape_flag;
}
void set_state(uint8 state_temp)
{
	state = state_temp;
}
uint8 get_state()
{
	return state;
}

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION SAVE THE FLAGS IN THE GLOBAL VARIABLES*/

void (*ptr_terminal[N_PROCESS])() =
{
		/*Get the diferent menus from UART_TERM*/
		TERA_menu,
		show_set_hour,
		show_set_date,
		get_hour,
		get_date,
		write_mem,
		read_mem
};

void set_past_state(uint8 state_temp)
{
	past_state = state_temp;
}
uint8 get_past_state()
{
	return past_state;
}

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*SECTION TO ACCESS A CERTAIN STATE OF A FUNCTION*/

void access_state(uint8 funct_state)
{
	/*Secure that we don't pass a limit*/
	if((HIGH_LIMIT >= funct_state) || (LOW_LIMIT <= funct_state))
	{
		*ptr_terminal[funct_state]();
	}
}
