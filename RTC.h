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

#define WRITE_CONTROL 0XDE

void RTC_set_sec(uint8 data);
uint8 RTC_get_sec(void);

void RTC_delay(uint32 delay);

#endif /* RTC_H_ */
