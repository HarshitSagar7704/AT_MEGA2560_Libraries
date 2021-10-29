/*
 * Interrupt.c
 *
 * Created: 7/12/2021 3:17:20 PM
 *  Author: asus
 */ 
#include "Interrupt.h"
#include "Input_Output.h"
/*
* Function Name:	interruptDisable.
* Input:			Interrupt Number.
* Output:			Interrupt will Disable.
* Example:          interruptDisable(Int0);
*/
void interruptDisable(uint8_t interrupt)
{
	switch(interrupt)
	{
		case 0:
		write(&EIMSK,INT0,LOW);
		break;
		case 1:
		write(&EIMSK,INT1,LOW);
		break;
		case 2:
		write(&EIMSK,INT2,LOW);
		break;
		case 3:
		write(&EIMSK,INT3,LOW);
		break;
		case 4:
		write(&EIMSK,INT4,LOW);
		break;
		case 5:
		write(&EIMSK,INT5,LOW);
		break;
		case 6:
		write(&EIMSK,INT6,LOW);
		break;
		case 7:
		write(&EIMSK,INT7,LOW);
		break;
	}
}
/*
* Function Name:	interruptEnable.
* Input:			Interrupt Number,Sense Control.
* Output:			Interrupt will enable.
* Example:          interruptEnable(Int0,rising);
*/
void interruptEnable(uint8_t interrupt,uint8_t Sense)
{
	switch(interrupt)
	{
		case 0:
		direction(&PORTD,PIND0,INPUT);
		write(&EIMSK,INT0,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRA,ISC00,HIGH);
			write(&EICRA,ISC01,HIGH);
			break;
			case 1:
			write(&EICRA,ISC00,HIGH);
			write(&EICRA,ISC01,LOW);
			break;
			case 2:
			write(&EICRA,ISC00,LOW);
			write(&EICRA,ISC01,HIGH);
			break;
			case 3:
			write(&EICRA,ISC00,HIGH);
			write(&EICRA,ISC01,HIGH);
			break;
		}
		break;
		case 1:
		direction(&PORTD,PIND1,INPUT);
		write(&EIMSK,INT1,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRA,ISC10,LOW);
			write(&EICRA,ISC11,LOW);
			break;
			case 1:
			write(&EICRA,ISC10,HIGH);
			write(&EICRA,ISC11,LOW);
			break;
			case 2:
			write(&EICRA,ISC10,LOW);
			write(&EICRA,ISC11,HIGH);
			break;
			case 3:
			write(&EICRA,ISC10,HIGH);
			write(&EICRA,ISC11,HIGH);
			break;
		}
		break;
		case 2:
		direction(&PORTD,PIND2,INPUT);
		write(&EIMSK,INT2,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRA,ISC20,LOW);
			write(&EICRA,ISC21,LOW);
			break;
			case 1:
			write(&EICRA,ISC20,HIGH);
			write(&EICRA,ISC21,LOW);
			break;
			case 2:
			write(&EICRA,ISC20,LOW);
			write(&EICRA,ISC21,HIGH);
			break;
			case 3:
			write(&EICRA,ISC20,HIGH);
			write(&EICRA,ISC21,HIGH);
			break;
		}
		break;
		case 3:
		direction(&PORTD,PIND3,INPUT);
		write(&EIMSK,INT3,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRA,ISC30,LOW);
			write(&EICRA,ISC31,LOW);
			break;
			case 1:
			write(&EICRA,ISC30,HIGH);
			write(&EICRA,ISC31,LOW);
			break;
			case 2:
			write(&EICRA,ISC30,LOW);
			write(&EICRA,ISC31,HIGH);
			break;
			case 3:
			write(&EICRA,ISC30,HIGH);
			write(&EICRA,ISC31,HIGH);
			break;
		}
		break;
		case 4:
		direction(&PORTE,PINE4,INPUT);
		write(&EIMSK,INT4,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRB,ISC40,LOW);
			write(&EICRB,ISC41,LOW);
			break;
			case 1:
			write(&EICRB,ISC40,HIGH);
			write(&EICRB,ISC41,LOW);
			break;
			case 2:
			write(&EICRB,ISC40,LOW);
			write(&EICRB,ISC41,HIGH);
			break;
			case 3:
			write(&EICRB,ISC40,HIGH);
			write(&EICRB,ISC41,HIGH);
			break;
		}
		break;
		case 5:
		direction(&PORTE,PINE5,INPUT);
		write(&EIMSK,INT5,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRB,ISC50,LOW);
			write(&EICRB,ISC51,LOW);
			break;
			case 1:
			write(&EICRB,ISC50,HIGH);
			write(&EICRB,ISC51,LOW);
			break;
			case 2:
			write(&EICRB,ISC50,LOW);
			write(&EICRB,ISC51,HIGH);
			break;
			case 3:
			write(&EICRB,ISC50,HIGH);
			write(&EICRB,ISC51,HIGH);
			break;
		}
		break;
		case 6:
		direction(&PORTE,PINE6,INPUT);
		write(&EIMSK,INT6,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRB,ISC60,LOW);
			write(&EICRB,ISC61,LOW);
			break;
			case 1:
			write(&EICRB,ISC60,HIGH);
			write(&EICRB,ISC61,LOW);
			break;
			case 2:
			write(&EICRB,ISC60,LOW);
			write(&EICRB,ISC61,HIGH);
			break;
			case 3:
			write(&EICRB,ISC60,HIGH);
			write(&EICRB,ISC61,HIGH);
			break;
		}
		break;
		case 7:
		direction(&PORTE,PINE7,INPUT);
		write(&EIMSK,INT7,HIGH);
		switch(Sense)
		{
			case 0:
			write(&EICRB,ISC70,LOW);
			write(&EICRB,ISC71,LOW);
			break;
			case 1:
			write(&EICRB,ISC70,HIGH);
			write(&EICRB,ISC71,LOW);
			break;
			case 2:
			write(&EICRB,ISC70,LOW);
			write(&EICRB,ISC71,HIGH);
			break;
			case 3:
			write(&EICRB,ISC70,HIGH);
			write(&EICRB,ISC71,HIGH);
			break;
		}
		break;
	}
	
	sei();
}