/*
 * UART_TERM.h
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#ifndef UART_TERM_H_
#define UART_TERM_H_

#include "Bits.h"
#include "UART.h"
#include "UART_DECO.h"
#include "RTC.h"

typedef enum
{
	ASCII_LETTER_A = 65,
	ASCII_LETTER_B = 66,
	ASCII_LETTER_C = 67,
	ASCII_LETTER_D = 68,
	ASCII_LETTER_E = 69,
	ASCII_LETTER_F = 70,
	ASCII_LETTER_a = 97,
	ASCII_LETTER_b = 98,
	ASCII_LETTER_c = 99,
	ASCII_LETTER_d = 100,
	ASCII_LETTER_e = 101,
	ASCII_LETTER_f = 102
}ASCII_type;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct to show the default menu
 	 \param[in] void
 	 \return void
 */
void TERA_menu(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct that help to set the time
 	 \param[in] void
 	 \return void
 */
void show_set_hour(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct that help to get the time
 	 \param[in] void
 	 \return void
 */
void get_hour(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct that help to get the time
 	 \param[in] void
 	 \return void
 */
void refresh_hour(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct that help to set the date
 	 \param[in] void
 	 \return void
 */
void show_set_date(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct that help to get the date
 	 \param[in] void
 	 \return void
 */
void get_date(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct that help to get the time
 	 \param[in] void
 	 \return void
 */
void refresh_date(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct used to write in memory
 	 \param[in] void
 	 \return void
 */
void write_mem(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct used to read the memory
 	 \param[in] void
 	 \return void
 */
void read_mem(void);

#endif /* UART_TERM_H_ */
