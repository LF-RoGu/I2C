/*
 * RTC.c
 *
 *  Created on: Nov 1, 2018
 *      Author: LuisFernando
 */
/*Ref BCD;
 * https://stackoverflow.com/questions/35370200/converting-decimal-to-bcd
 * */

#include "RTC.h"

void RTC_set_sec(uint8 data)
{
	if(data > 59)
		data = 0;
	uint8 BCD = (data % 10);
	/**/
	BCD |= (data/10)<<BIT4;

	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(1000);

	/*Register address*/
	I2C_write_byte(0x02); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(1000);

	/*BCD code*/
	I2C_write_byte(data); /*Dato que se envia*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(1000);
	/*Send the stop signal*/
	I2C_stop();
	/*Delay to secure we get the signal*/
	RTC_delay(1000);
}
uint8 RTC_get_sec()
{
	uint8 data;
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
//	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();

	/*Register address*/
//	I2C_write_byte(/*Address*/);
	/*Check if I2C is busy*/
	I2C_wait();
	/**/
	I2C_get_ack();

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();
	/*Writing to the slave to read the previous register*/
//	I2C_write_byte(/*Address*/);
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

void RTC_delay(uint32 delay){
	uint32 i=delay;
	while(i!=0){
		i--;
	}
}
