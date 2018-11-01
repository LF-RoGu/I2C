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
		I2C0->C1 = I2C_C1_IICIE_MASK;
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
		I2C1->C1 = I2C_C1_IICIE_MASK;
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
		I2C2->C1 = I2C_C1_IICIE_MASK;
		break;
	default:
		break;
	}
}
uint8_t I2C_busy()
{
	/*Verify that the module is not busy so it can continue*/
	if(I2C0->S && I2C_S_BUSY_MASK)
		return TRUE;
	else
		return FALSE;
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
		I2C0->C1 &= ~(I2C_C1_TX_MASK);
		I2C0->C1 &= ~(I2C_C1_TXAK_MASK);
	}
	else
	{
		/*Transmit mode*/
		I2C0->C1 |= I2C_C1_TX_MASK;
	}
}
