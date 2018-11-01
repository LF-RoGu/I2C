/*
 * I2C.c
 *
 *  Created on: Oct 29, 2018
 *      Author: LuisFernando
 */

#include "I2C.h"

/*PCR config*/
static const GPIO_pinControlRegisterType I2C_PCR = GPIO_MUX2|GPIO_PS;

void I2C_init(i2c_channel_t channel, uint32_t system_clock, uint16_t baud_rate)
{
	uint32 valueSCL;
	/*Set the configuration for I2C_PCR_Tx*/
	GPIO_pin_control_register(GPIO_B,BIT2,&I2C_PCR);
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BIT2);
	/*Set the configuration for I2C_PCR_Rx*/
	GPIO_pin_control_register(GPIO_B,BIT3,&I2C_PCR);
	GPIO_data_direction_pin(GPIO_B,GPIO_INPUT,BIT3);

	/*I2C baud rate = I2C module clock speed (Hz)/(mul × SCL divider)*/
	valueSCL = system_clock/(baud_rate*MULT);

	switch(channel)
	{
	case I2C_0:
		SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
		/*ClockRate*/
		I2C0->F = I2C_F_ICR(valueSCL);
		/*Multiplier Factor
		 * 00 mul = 1
		 * 01 mul = 2
		 * 10 mul = 4
		 * 11 Reserved
		 * */
		I2C0->F = I2C_F_MULT(2);
		/*Enable I2C module*/
		I2C0->C1 = I2C_C1_IICEN_MASK;
		break;
	case I2C_1:
		SIM->SCGC4 |= SIM_SCGC4_I2C1_MASK;
		/*ClockRate*/
		I2C1->F = I2C_F_ICR(valueSCL);
		/*Multiplier Factor
		 * 00 mul = 1
		 * 01 mul = 2
		 * 10 mul = 4
		 * 11 Reserved
		 * */
		I2C1->F = I2C_F_MULT(2);
		/*Enable I2C module*/
		I2C1->C1 = I2C_C1_IICEN_MASK;
		break;
	case I2C_2:
		SIM->SCGC1 |= SIM_SCGC1_I2C2_MASK;
		/*ClockRate*/
		I2C2->F = I2C_F_ICR(valueSCL);
		/*Multiplier Factor
		 * 00 mul = 1
		 * 01 mul = 2
		 * 10 mul = 4
		 * 11 Reserved
		 * */
		I2C2->F = I2C_F_MULT(2);
		/*Enable I2C module*/
		I2C2->C1 = I2C_C1_IICEN_MASK;
		break;
	default:
		break;
	}
}
uint8_t I2C_busy()
{
	/*Verify that the module is not busy so it can continue*/
	if(I2C0->S && I2C_S_BUSY_MASK)
		return TRUE;  /*If this case, then the I2C is available*/
	else
		return FALSE; /*If this case, then the I2C is busy*/
}
void I2C_mst_or_slv_mode(uint8_t mst_or_slv)
{
	if(TRUE == mst_or_slv)
	{
		/*Master mode*/
		I2C0->C1 |= I2C_C1_MST_MASK;
	}
	else
	{
		/*Slave mode*/
		I2C0->C1 &= ~(I2C_C1_MST_MASK);
	}
}
void I2C_tx_rx_mode(uint8_t tx_or_rx)
{
	if(TRUE == tx_or_rx)
	{
		/*Receive mode*/
		/*Transmit Mode
		 *Selects the direction of master and slave transfers.
		 *0 Receive
		 *1 Transmit
		 */
		I2C0->C1 &= ~(I2C_C1_TX_MASK);
		/*Transmit Acknowledge
		 *Specifies the value driven onto the SDA during data acknowledge cycles for both master and slave
		 *0 An acknowledge signal is sent to the bus on the following receiving byte (if FACK is cleared) or the
current receiving byte (if FACK is set).
		 *1 No acknowledge signal is sent to the bus on the following receiving data byte (if FACK is cleared) or
the current receiving data byte (if FACK is set).*/
		I2C0->C1 &= ~(I2C_C1_TXAK_MASK);
	}
	else
	{
		/*Transmit mode*/
		I2C0->C1 |= I2C_C1_TX_MASK;
	}
}
void I2C_nack(void)
{
	I2C0->C1 |= I2C_C1_TXAK_MASK;
}
void I2C_repeted_start(void)
{
	/*Repeat START
	 *Writing 1 to this bit generates a repeated START condition provided it is the current master.*/
	I2C0->C1 |= I2C_C1_RSTA_MASK;
}
void I2C_write_byte(uint8_t data)
{
	/*Data I/O register
	 * In master transmit mode, when data is written to this register, a data transfer is initiated.*/
	I2C0->D = data;
}
uint8_t  I2C_read_byte(void);
void I2C_start(void)
{
	/*Generate the Start Signal*/
	I2C0->C1 |= I2C_C1_TX_MASK;
	I2C0->C1 |= I2C_C1_MST_MASK;
}
void I2C_stop(void)
{
	/*Generates the Stop Signal*/
	I2C0->C1 &= ~I2C_C1_TX_MASK;
	I2C0->C1 &= ~I2C_C1_MST_MASK;
}
uint8_t  I2C_read_byte(void);
void I2C_wait(void)
{
	/*Waits until the process TCF(Transfer Complete Flag) changes*/
	while(FALSE == (I2C0->S && I2C_S_IICIF_MASK));
}
uint8_t I2C_get_ack(void);
