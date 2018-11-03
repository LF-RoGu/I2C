/*
 * EEPROM.c
 *
 *  Created on: 03/11/2018
 *      Author: LuisFernando
 */

#include "EEPROM.h"

void writeMemory(uint16 address,uint8 data)
{
	/*Need to separate address to High and Low address*/
	/*high address*/
	uint8 Haddr = address >> 8;
	/*low address*/
	uint8 Laddr =  address;
	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(EEPROM_WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*imagino un delay aqui tambien*/

	/*Register address*/
	I2C_write_byte(Haddr); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*imagino un delay aqui tambien*/

	/*Register address*/
	I2C_write_byte(Laddr); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*imagino un delay aqui tambien*/

	/*Send the stop signal*/
	I2C_stop();
	/*imagino un delay aqui tambien*/
}
