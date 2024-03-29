/*
 * EEPROM.h
 *
 *  Created on: 03/11/2018
 *      Author: LuisFernando
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "Bits.h"
#include "I2C.h"

#define EEPROM_WRITE_CONTROL 0xAE
#define EEPROM_READ_CONTROL 0xAF

#define PAGE_SIZE 0x64

#define EEPROM_DELAY 1000

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*\brief Funct to write in the address wirtten in the param via I2C
 *\param[add] Address
 *\param[data] data to store
 * */
void EEPROM_write_mem(uint16 address,sint8 data);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*\brief Funct to write in the address wirtten in the param via I2C
 *\param[add] Address
 *\param[data] data to store
 * */
void EEPROM_write_string_mem(uint16 address,sint8* ptr_data);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*\brief Funct to read the address wirtten in the param via I2C
 *\param[add] Address
 * */
sint8 EEPROM_read_mem(uint16 address);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*\brief Funct to read the address wirtten in the param via I2C
 *\param[add] Address
 * */
sint8* EEPROM_read_string_mem(uint16 address);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*\brief Funct to clear the mem
 * */
void EEPROM_clear_mem();
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*\brief Funct to create a delay so we can read the data in the logic analyser
 *\param[add] delay
 * */
void EEPROM_delay(uint32 delay);

#endif /* EEPROM_H_ */
