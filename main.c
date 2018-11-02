/**
	\file
	\brief
		This project shows how works the emulation of a VT 100 in teraterm.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	27/07/2015
	\todo
		To implement the UART_init function
 */

#include "MK64F12.h" /* include peripheral declarations */
#include "UART.h"/**UART device driver*/
#include "NVIC.h"/**NVIC device driver*/
#include "RTC.h"
#include <stdio.h>

#define DEBUG
#define SYSTEM_CLOCK 21000000

#ifdef DEBUG
	#include "stdio.h"
#endif
/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

int main(void)
{
	/**Enables the clock of PortB in order to configures TX and RX of UART peripheral*/
	SIM->SCGC5 = SIM_SCGC5_PORTB_MASK;

	I2C_init(I2C_0,SYSTEM_CLOCK,BD_9600);

	RTC_set_sec(59);

	for (;;) {
	}
	
	return 0;
}
