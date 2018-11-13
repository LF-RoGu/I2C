/**
	\file
	\brief
	\author Luis Fernando Rodriguez, ie705694	@iteso.mx
	\date	05/11/2018
 */

#include "MK64F12.h" /* include peripheral declarations */
#include "UART.h"/**UART device driver*/
#include "NVIC.h"/**NVIC device driver*/
#include "RTC.h"
#include "Delay.h"
#include "UART_DECO.h"
#include "UART_TERM.h"
#include "EEPROM.h"
#include <stdio.h>


#define SYSTEM_CLOCK 21000000

#define ADDRESS_STRING 0x00FF
#define ADDRESS_CHAR 0x0000

/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

int main(void)
{
	sint8 word[] = {"Hello World"};
	/**Enables the clock of PortB in order to configures TX and RX of UART peripheral*/
	SIM->SCGC5 = SIM_SCGC5_PORTB_MASK;

	/*UART init*/
	UART_init(UART_0, SYSTEM_CLOCK, BD_9600);
	/*Debug to check if UART is configured*/
	printf("UART is configured");
	/*I2C init*/
	I2C_init(I2C_0, SYSTEM_CLOCK, BD_9600);
	/*Debug to check if I2C is configured*/
	printf("I2C is configured");

	/**Enables the UART 0 interrupt*/
	UART0_interruptEnable(UART_0);
	/**Enables the UART 0 interrupt in the NVIC*/
	NVIC_enableInterruptAndPriotity(UART0_IRQ, PRIORITY_10);


	EEPROM_write_mem(ADDRESS_CHAR,'b');
	EEPROM_read_mem(ADDRESS_CHAR);

	UART_putChar(UART_0,EEPROM_read_mem(ADDRESS_CHAR));

	EEPROM_write_string_mem(ADDRESS_STRING,word);
	EEPROM_read_string_mem(ADDRESS_STRING);
	/**Enables interrupts*/
	EnableInterrupts;

	for (;;) {
		refresh_mem(ADDRESS_STRING);
	}
	
	return 0;
}
