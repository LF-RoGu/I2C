/*
 * RTC.c
 *
 *  Created on: Nov 1, 2018
 *      Author: LuisFernando
 */

#include "RTC.h"

void RTC_get_sec(uint8 data)
{
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(/*Address*/);
	/*Recevie the Acknowledge*/
	I2C_get_ack();

	/*Register address*/
	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_busy();
	/**/
	I2C_get_ack();

	/**/
	I2C_repeted_start();
	/*Writing to the slave to read the previous register*/
	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_busy();
	/**/
	I2C_get_ack();
}
