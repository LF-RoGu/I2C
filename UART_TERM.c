/*
 * UART_TERM.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include "UART_TERM.h"

void show_menu()
{
	/**The following sentences send strings to PC using the UART_putString function. Also, the string
	 * is coded with terminal code*/
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0,"\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;32;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "1) Establecer Hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;11H");
	/** Set the text in a string*/
	UART_putString(UART_0, "2) Establecer Fecha\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;12H");
	/** Set the text in a string*/
	UART_putString(UART_0, "3) Leer hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;13H");
	/** Set the text in a string*/
	UART_putString(UART_0, "4) Leer fecha\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;14H");
	/** Set the text in a string*/
	UART_putString(UART_0, "5) Escribir mensaje en memoria I2C\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;15H");
	/** Set the text in a string*/
	UART_putString(UART_0, "7) Mostrar mensaje\r");
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
void get_hour(void)
{
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0,"\033[2J");
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;30;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "RealTime:\r");
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
void show_set_hour()
{
	/*Funct to print in the screen the menu to set the hour*/
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;32;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Write in format HH/MM/SS\r");
}

void show_set_date(void)
{
	/*Funct to print in the screen the menu to set the date*/
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;32;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Write in format DD/MM/YY\r");
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
void write_mem()
{
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;32;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Write text to storage\r");
}
