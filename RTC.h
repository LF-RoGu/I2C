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

#define SEC_MAX 59
#define BTC_TEN 10
/*Constants for the address for HH/MM/SS*/
#define SEC_ADDR 0x00
#define MIN_ADDR 0x01
#define HOUR_ADDR 0x02
/*Constants for the address for YYYY/MM/DD*/
#define DAY_ADDR 0x04
#define MONTH_ADDR 0X05
#define YEAR_ADDR 0X06

void RTC_set_sec(uint8 data);
uint8 RTC_get_sec(void);

void RTC_delay(uint32 delay);

#endif /* RTC_H_ */
