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

static uint8 data = FALSE;

static uint8 sec = FALSE,
	    	 min = FALSE,
			 hrs = FALSE;

void RTC_write(uint8 Address, uint8 data)
{
	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(Address); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*BCD code*/
	I2C_write_byte(data); /*Dato que se envia*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*Send the stop signal*/
	I2C_stop();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
}
void RTC_read(uint8 Address)
{
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(Address);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();

	/*Writing to the slave to read the previous register*/
	I2C_write_byte(RTC_READ_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Chance I2C module to Rx mode*/
	I2C_tx_rx_mode(I2C_RX);

	/*Generate ~Acknowledge*/
	I2C_nack();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*Check if I2C is busy*/
	I2C_wait();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the stop signal*/
	I2C_stop();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();

	return (data);
}
void RTC_enable()
{
	RTC_write(ENABLE_ADDR,ENABLE_COUNT);
}

void RTC_set_sec(uint8 RTCsec)
{
	uint8 BCDtemp1 = FALSE,
		  BCDtemp2 = FALSE,
		  BCD      = FALSE;

	BCDtemp1 = (RTCsec / TEN);
	BCDtemp2 = (RTCsec - (BCDtemp1*TEN));
	BCD = (BCDtemp1<<SHIFT);
	BCD = (BCD | BCDtemp2 | (ST<<SHIFT7));

	RTC_write(SEC_ADDR,BCD);
}
uint8 RTC_get_sec()
{
	sec = RTC_read(SEC_ADDR);
	sec = (((sec >> SHIFT) & HEX_MASK) * TEN) + (HEX_MASK & sec);
	return sec;
}

void RTC_set_min(uint8 RTCmin)
{
	uint8 BCDtemp1 = FALSE,
		  BCDtemp2 = FALSE,
	      BCD      = FALSE;

	BCDtemp1 = (RTCsec / TEN);
	BCDtemp2 = (RTCsec - (BCDtemp1 * TEN));
	BCD = (BCDtemp1 << SHIFT);
	BCD = (BCD | BCDtemp2);

	RTC_write(SEC_ADDR,BCD);
}
uint8 RTC_get_min(void)
{
	min = RTC_read(MIN_ADDR);
	min = (((min >> SHIFT) & HEX_MASK) * TEN) + (HEX_MASK & min);
	return min;
}

void RTC_set_hour(uint8 RTChrs)
{
	uint8 BCDtemp1 = FALSE,
		  BCDtemp2 = FALSE,
		  BCD      = FALSE;

	BCDtemp1 = (RTCsec / TEN);
	BCDtemp2 = (RTCsec - (BCDtemp1 * TEN));
	BCD = (BCDtemp1 << SHIFT);
	BCD = (BCD | BCDtemp2);

	RTC_write(SEC_ADDR,BCD);
}
uint8 RTC_get_hour(void)
{
	hrs = RTC_read(HOUR_ADDR);
	hrs = (((hrs >> SHIFT) & HEX_MASK) * TEN) + (HEX_MASK & hrs);
	return hrs;
}

void RTC_set_date(uint8 RTCdate)
{
	uint8 BCDtemp1 = FALSE,
		  BCDtemp2 = FALSE,
	      BCD      = FALSE;

	BCDtemp1 = (RTCdate / TEN);
	BCDtemp2 = (RTCdate - (BCDtemp1 * TEN));
	BCD = (BCDtemp1 << SHIFT);
	BCD = (BCD | BCDtemp2);

	RTC_write(SEC_ADDR,BCD);
}

void RTC_set_month(uint8 RTCmonth)
{
	uint8 BCDtemp1 = FALSE,
	      BCDtemp2 = FALSE,
		  BCD      = FALSE;

	BCDtemp1 = (RTCdate / TEN);
	BCDtemp2 = (RTCdate - (BCDtemp1 * TEN));
	BCD = (BCDtemp1 << SHIFT);
	BCD = (BCD | BCDtemp2);

	RTC_write(SEC_ADDR,BCD);
}

void RTC_set_year(uint8 RTCyear)
{
	uint8 BCDtemp1 = FALSE,
		  BCDtemp2 = FALSE,
		  BCD      = FALSE;

	BCDtemp1 = (RTCdate / TEN);
	BCDtemp2 = (RTCdate - (BCDtemp1 * TEN));
	BCD = (BCDtemp1 << SHIFT);
	BCD = (BCD | BCDtemp2);

	RTC_write(SEC_ADDR,BCD);
}
/**/
void RTC_delay(uint32 delay){
	uint32 i=delay;
	while(i!=0){
		i--;
	}
}
