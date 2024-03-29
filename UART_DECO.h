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
#include "UART_TERM.h"
#include "UART.h"
#include "PIT.h"
#include "Delay.h"
#include "EEPROM.h"

#define DECENA 10
#define CENTENA 100
#define MILLAR 1000
#define DECENA_MILLAR 10000

#define ASCII_CONV 48

#define SEC_INIT 0x80

#define SIZE 6
#define TXT_SIZE 30
#define TEN 10
#define LOW_LIMIT 0
#define HIGH_LIMIT 8
#define PTR_SIZE 8

#define ADDRESS_INIT 0x0000

#define DELAY 65000

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
	ASCII_ENTER = 13,
	ASCII_ESC = 27
}Deco_type;

typedef enum {
	MASSAGE_0 ,
	MASSAGE_1 ,
	MASSAGE_2 ,
	MASSAGE_3 ,
	MASSAGE_4 ,
	MASSAGE_5
}message_type;

typedef enum {
	MENU,
	SET_HOUR,
	SET_DATE,
	READ_HOUR,
	READ_DATE,
	WRITE_MEM,
	SHOW_MEM,
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
void value_capture(uint32 value);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get the units form a hole value
 	 \param[in] void
 	 \return value + ASCII
 */
uint8 get_unidad(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get the units form a hole value
 	 \param[in] void
 	 \return value + ASCII
 */
uint8 get_decena(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get the units form a hole value
 	 \param[in] void
 	 \return value + ASCII
 */
uint8 get_centena(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get the units form a hole value
 	 \param[in] void
 	 \return value + ASCII
 */
uint8 get_millar(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get the units form a hole value
 	 \param[in] void
 	 \return value + ASCII
 */
uint8 get_decenaMillar(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to set a previous state
 	 \param[in] state
 	 \return void
 */
void set_past_state(uint8 state);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get a previous state
 	 \param[in] void
 	 \return state
 */
uint8 get_past_state(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct set limits to the states, so the pointer don't access a forbidden place
 	 \param[in] void
 	 \return state
 */
void fptr_function(uint8 funct);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to show and execute a certain process
 	 \param[in] void
 	 \return void
 */
void set_state(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to set a flag if a key was pressed
 	 \param[in] flag
 	 \return void
 */
void set_key(uint8 key);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get a flag if a key was pressed
 	 \param[in] void
 	 \return flag
 */
uint8 get_key(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to set a flag if enter was pressed
 	 \param[in] flag
 	 \return void
 */
void set_enter(uint8 enter);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get a flag if enter was pressed
 	 \param[in] void
 	 \return flag
 */
uint8 get_enter(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to set a flag if enter was pressed
 	 \param[in] flag
 	 \return void
 */
void set_esc(uint8 esc);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to get a flag if enter was pressed
 	 \param[in] void
 	 \return flag
 */
uint8 get_esc(void);
#endif /* UART_DECO_H_ */
