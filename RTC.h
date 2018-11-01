/*
 * RTC.h
 *
 *  Created on: Nov 1, 2018
 *      Author: LuisFernando
 */

#ifndef RTC_H_
#define RTC_H_

#include "Bits.h"
#include "GPIO.h"
#include "I2C.h"

void RTC_set_sec(uint8 data);
uint8 RTC_get_sec(void);

#endif /* RTC_H_ */
