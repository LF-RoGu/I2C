/*
 * UART_TERM.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include "UART_TERM.h"

void TERA_menu()
{
	/**The following sentences send strings to PC using the UART_putString function. Also, the string
	 * is coded with terminal code*/
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;37;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0,"\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;37;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "1) Establecer Hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[11;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "2) Establecer Fecha\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[12;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "3) Leer hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[13;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "4) Leer fecha\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[14;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "5) Escribir mensaje en memoria I2C\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[15;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "7) Mostrar mensaje\r");
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
void show_set_hour()
{
	/*Funct to print in the screen the menu to set the hour*/
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;37;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;37;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Write in format HH/MM/SS\r");
}

void get_hour()
{
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;37;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0,"\033[2J");
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;37;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "RealTime:\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[11;10H");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_hour());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0,get_decena());
	UART_putChar(UART_0,get_unidad());
	/*Prints : for the format*/
	UART_putString(UART_0, ":");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_min());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_decena());
	UART_putChar(UART_0, get_unidad());
	/*Prints : for the format*/
	UART_putString(UART_0, ":");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_sec());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_decena());
	UART_putChar(UART_0, get_unidad());
}

void refresh_hour()
{
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[11;10H");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_hour());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_decena());
	UART_putChar(UART_0, get_unidad());
	/*Prints : for the format*/
	UART_putString(UART_0, ":");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_min());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_decena());
	UART_putChar(UART_0, get_unidad());
	/*Prints : for the format*/
	UART_putString(UART_0, ":");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_sec());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_decena());
	UART_putChar(UART_0, get_unidad());
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
void show_set_date(void)
{
	/*Funct to print in the screen the menu to set the date*/
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;37;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;37;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Write in format DD/MM/YY\r");
}

void get_date(void)
{
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0, "\033[0;37;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0, "\033[0;37;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Date:\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[11;10H");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_date());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_unidad());
	UART_putChar(UART_0, get_decena());
	/*Prints : for the format*/
	UART_putString(UART_0, "/");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_month());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_unidad());
	UART_putChar(UART_0, get_decena());
	/*Prints : for the format*/
	UART_putString(UART_0, "/");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_year());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_unidad());
	UART_putChar(UART_0, get_decena());
}

void refresh_date()
{
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[11;10H");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_date());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_unidad());
	UART_putChar(UART_0, get_decena());
	/*Prints : for the format*/
	UART_putString(UART_0, "/");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_month());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_unidad());
	UART_putChar(UART_0, get_decena());
	/*Prints : for the format*/
	UART_putString(UART_0, "/");
	/** Gets the value in the register of time, corresponding to Hrs*/
	value_capture(RTC_get_year());
	/** Print the value of the register once it got deco*/
	UART_putChar(UART_0, get_unidad());
	UART_putChar(UART_0, get_decena());
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/
void write_mem()
{
	/** VT100 command for text in black and background in black*/
	UART_putString(UART_0,"\033[0;37;40m");
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0, "\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_putString(UART_0, "\033[0;37;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Write text to storage\r");
}
