/*
 * RTC.c
 *
 *  Created on: Nov 1, 2018
 *      Author: LuisFernando
 */

#include "RTC.h"
void RTC_set_sec(uint8 data)
{
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(/*WriteControl*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();

	/*Register address*/
	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();

	/*BCD code*/
	I2C_write_byte(/*BCD*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Send the stop signal*/
	I2C_stop();
}
uint8 RTC_get_sec()
{
	uint8 data;
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();

	/*Register address*/
	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/**/
	I2C_get_ack();

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();
	/*Writing to the slave to read the previous register*/
	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/**/
	I2C_get_ack();

	/*Chance I2C module to Rx mode*/
	I2C_tx_rx_mode(I2C_RX);

	/*Generate ~Acknowledge*/
	I2C_nack();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*Check if I2C is busy*/
	I2C_wait();

	/*Send the stop signal*/
	I2C_stop();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();

	return (data);
}
