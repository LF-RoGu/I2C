/*
 * EEPROM.c
 *
 *  Created on: 03/11/2018
 *      Author: LuisFernando
 */

#include "EEPROM.h"

void writeMemory(uint16 address,uint8 data)
{
	/*Start bit*/
	I2C_start();
}
