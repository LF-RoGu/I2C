/*
 * I2C.c
 *
 *  Created on: Oct 29, 2018
 *      Author: LuisFernando
 */

#include "I2C.h"

void I2C_init(i2c_channel_t channel, uint32_t system_clock, uint16_t baud_rate)
{
	uint32 valueSCL;
	uint8 mult = 1;

	/*I2C baud rate = I2C module clock speed (Hz)/(mul × SCL divider)*/
	valueSCL = system_clock/(baud_rate*mult);
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
		I2C0->F = I2C_F_MULT(0);
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
		I2C1->F = I2C_F_MULT(0);
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
		I2C2->F = I2C_F_MULT(0);
		/*Enable I2C module*/
		I2C2->C1 = I2C_C1_IICIE_MASK;
		break;
	default:
		break;
	}
}
uint8_t I2C_busy();
