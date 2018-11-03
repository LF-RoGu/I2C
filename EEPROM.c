/*
 * EEPROM.c
 *
 *  Created on: 03/11/2018
 *      Author: LuisFernando
 */

#include "EEPROM.h"

void write_mem(uint16 address,uint8 data)
{
	/*Need to separate address to High and Low address*/
	/*high address*/
	uint8 Haddr = address >> BIT8;
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

uint8 read_mem(uint16 address)
{
	uint8 data;
	/*high address*/
	uint8 Haddr = address >> BIT8;
	/*low address*/
	uint8 Laddr = address;

	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(EEPROM_WRITE_CONTROL); /*1010/Direccion fisica(A2/A1/A0)*/
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

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();

	/*Send the RTC Address to the register*/
	I2C_write_byte(EEPROM_READ_CONTROL); /*1010/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*imagino un delay aqui tambien*/

	/*Chance I2C module to Rx mode*/
	I2C_tx_rx_mode(I2C_RX);

	/*Generate ~Acknowledge*/
	I2C_nack();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*Check if I2C is busy*/
	I2C_wait();
	/*imagino un delay aqui tambien*/

	/*Send the stop signal*/
	I2C_stop();

	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*imagino un delay aqui tambien*/
	return (data);
}
