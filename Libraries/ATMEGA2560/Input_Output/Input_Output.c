/*
 * Input_Output.c
 *
 * Created: 7/12/2021 1:42:54 PM
 * Author : asus
 */ 
#include "Input_Output.h"
/*
* Function Name:	direction
* Input:			PORT , PIN , Direction of PIN.
* Output:			NONE
* Example:          direction(&PORTB,PINB0,OUTPUT); // DDRB = 0x01;
*/
void direction(uint8_t *port,uint8_t pin,bool dir)
{
	uint8_t *ddr;// Declaring pointer for store address of direction register.
	ddr=port -1;// As given in data sheet address of direction register is 1 less than portxn register.
	if(dir==OUTPUT)
	{
		*ddr |= 1<<(pin);
	}
	else if (dir==INPUT)
	{
		*ddr &= ~(1<<(pin));
	}
}
/*
* Function Name:	write.
* Input:			PORT , PIN , STATE of pin.
* Output:			NONE.
* Example:          write(&PORTB,PINB0,LOW); // PORTB =0x00;
*/
void write(uint8_t *port,uint8_t pin,bool state)
{
	
	if(state==HIGH)
	{
		*port |= 1<<(pin);
	}
	else if (state==LOW)
	{
		*port &= ~(1<<(pin));
	}
}
/*
* Function Name:	read.
* Input:			PIN-PORT, PIN-NO.
* Output:			PIN-STATE.
* Example:          read(&PINB,PINB1);
*/
int read(uint8_t portpin,uint8_t pin_no)
{
	uint8_t pinState = (portpin & (1 << pin_no)) >> pin_no;
	return (pinState);
}

