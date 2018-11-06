#include  "Delay.h"

void delay(uint16_t delay)
{
	volatile uint16_t counter;

	for(counter = delay; counter > 0; counter--)
	{
	}
}
void sleep(void){
	uint8_t i;
	for( i=0 ; i<50 ;i++)
	delay(65000);
}
void sleep_sec(void){
	uint8_t i;
	for( i=0 ; i<20 ;i++)
	delay(65000);
}
