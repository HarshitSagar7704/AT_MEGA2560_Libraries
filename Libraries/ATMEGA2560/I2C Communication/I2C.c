/*
 * Usart.c
 *
 * Created: 8/7/2021 1:50:04 PM
 *  Author: asus
 */ 
#include "I2C.h"
void Twi_start(void)
{
	TWSR = 0x00;
	TWBR = (F_CPU / 100000UL - 16) / 2;
}
unsigned char twi_tran(unsigned char type)
{
	switch(type)
	{
		case twi_start:
			TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
			break;
		case twi_data:
			TWCR = (1<<TWINT)|(1<<TWEN);
			break;
		case twi_stop:
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
			return 0;
	}
			

while (!(TWCR&(1<<TWINT)));
return(TWSR&0xF8);
}
int twi_transmit_data(uint8_t twi_address,uint8_t data)
{
	unsigned char n = 0;
	unsigned char twi_status;
	char r_val = -1;
	twi_retry:
		if(n++>=MAX_TRIES)
		return r_val;
		twi_status=twi_tran(twi_start);
		if(twi_status==TWI_ARB_LOST)
		goto twi_retry;
		if((twi_status!=twi_start)&&(twi_status!=TWI_REP_START))
		goto twi_quit;
		TWDR = twi_address | 0 ;
		twi_status = twi_tran(twi_data);
		if((twi_status==TWI_SLA_NACK)||(twi_status==TWI_ARB_LOST))
		goto twi_retry;
		if(twi_status!=TWI_SLA_ACK)
		goto twi_quit;
		r_val = 1;
		twi_quit:
		twi_status = twi_tran(twi_stop);
		return r_val;
	
}











