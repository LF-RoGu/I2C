/*
 * EEPROM.h
 *
 *  Created on: 03/11/2018
 *      Author: LuisFernando
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#define WRITE_CONTROL 0xAE
#define READ_CONTROL 0xAF

/*\brief Funct to write in the address wirtten in the param via I2C
 *\param[add] Address
 *\param[data] data to store
 * */
void writeMemory(uint16 address,uint8 data);

#endif /* EEPROM_H_ */
