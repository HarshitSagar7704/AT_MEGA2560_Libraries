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
	TWBR = 0x0C;
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
		{
			goto twi_retry;	
		}
		if((twi_status!=TWI_START)&&(twi_status!=TWI_REP_START))
		{
		goto twi_quit;
		}
		TWDR = twi_address ;
		twi_status=twi_tran(twi_data);
		if ((twi_status == TWI_SLA_NACK) || (twi_status == TWI_ARB_LOST)) 
		goto twi_retry;  
		if (twi_status != TWI_SLA_ACK) 
		goto twi_quit;
		TWDR = data; 
		twi_status=twi_tran(twi_data);  
		if (twi_status != TWI_DATA_ACK) 
		goto twi_quit;    
		r_val=1;
		twi_quit:
		twi_status=twi_tran(twi_stop); 
		return r_val;
}

uint8_t twi_receive_data(uint8_t twi_address)
{
	unsigned char n = 0;
	unsigned char twi_status;
	char r_val = -1;
	uint8_t set;
	twi_retry:
	if(n++>=MAX_TRIES)
	return r_val;
	twi_status=twi_tran(twi_start);
	if(twi_status==TWI_ARB_LOST)
	{
		goto twi_retry;
	}
	if((twi_status!=TWI_START)&&(twi_status!=TWI_REP_START))
	{
		goto twi_quit;
	}
	TWDR = twi_address;
	twi_status=twi_tran(twi_data);
	if ((twi_status == TWI_SLA_NACK) || (twi_status == TWI_ARB_LOST))
	goto twi_retry;
	if (twi_status != TWI_SLA_ACK)
	goto twi_quit;
	set = TWDR;
	read_data = set;
	if (twi_status != TWI_DATA_ACK)
	goto twi_quit;
	r_val=1;
	twi_quit:
	twi_status=twi_tran(twi_stop);
	return r_val;
}

char *int_to_str(uint8_t num, uint8_t len)
{
	uint8_t i;
	char *str;
	str[len]='\0';
	for(i=(len-1); i>=0; i--)
	{
		str[i] = '0' + num % 10;
		num/=10;
	}
	return str;
}







