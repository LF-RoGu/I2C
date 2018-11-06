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
#include "Delay.h"
#include "UART_DECO.h"
#include "UART_TERM.h"
#include <stdio.h>

#define SYSTEM_CLOCK 21000000

/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

int main(void)
{
	uint8 i,j;
	/**Enables the clock of PortB in order to configures TX and RX of UART peripheral*/
	SIM->SCGC5 = SIM_SCGC5_PORTB_MASK;
	/*UART init*/
	UART_init(UART_0,SYSTEM_CLOCK,BD_9600);
	/*Debug to check if UART is configured*/
	printf("UART is configured");
	/*I2C init*/
	I2C_init(I2C_0,SYSTEM_CLOCK,BD_9600);
	/*Debug to check if I2C is configured*/
	printf("I2C is configured");
	/**Enables the UART 0 interrupt*/
	UART0_interruptEnable(UART_0);
	/**Enables the UART 0 interrupt in the NVIC*/
	NVIC_enableInterruptAndPriotity(UART0_IRQ, PRIORITY_10);


	show_menu();

	RTC_enable();

	RTC_set_sec(30);
	RTC_set_min(28);
	RTC_set_hour(13);

	/**Enables interrupts*/
	EnableInterrupts;

	for (;;) {
		if(i > 59)
		{
			j++;
			i = 0;
			RTC_set_min(j);
		}

		if(j > 59)
			j = 0;
		get_hour();
		sleep_sec();
		i++;
		RTC_set_sec(i);
	}
	
	return 0;
}
