/*
 * Usart.c
 *
 * Created: 8/7/2021 1:50:04 PM
 *  Author: asus
 */ 
#include "Usart.h"
void Usar0tInit(void)
{
	Usart0.ubrr = (uint16_t)((Usart0.Fosc/Usart0.baudrate/16)-1);	
	UCSR0A = 0x00;//Setting default values of register.
	UCSR0B = 0x00;//Setting default values of register.
	UCSR0C = 0x00;//Setting default values of register.	
	UCSR0C |= (uint8_t)((Usart0.usartMode)<<6);			
	UCSR0A |= (uint8_t)(((Usart0.operatingMode)&0x01)<<1);					
	if(Usart0.operatingMode == Normal || Usart0.operatingMode == Double)								
	{
		
		Usart0.ubrr = (uint16_t)((Usart0.Fosc/Usart0.baudrate/16)-1); 
		UCSR0B |= (0x98);// Enable Tx and Rx.
		UCSR0C |= (uint8_t)(((Usart0.characterSize) & 0x03)<<1);// setting Frame format.
		UCSR0B |= (uint8_t)((Usart0.characterSize)&0x04);// setting Frame format.
		UCSR0C |= (uint8_t)((Usart0.stopBitSelect)<<3);// setting number of stop bits.
		UCSR0C |= (uint8_t)((Usart0.parityMode)<<4);// setting parity mode.
		UCSR0C |= (uint8_t)((Usart0.clockPolarity));// setting clock polarity.
	}
	else if(Usart0.operatingMode == Master)
	{
		UBRR0H = 0x00;
		UBRR0L = 0x00;
		DDRE |= 0x04; 
		UCSR0C |= (uint8_t)(Usart0.spiDatamode);
		UCSR0B = 0x18;// Enable Tx and Rx.
	}	
	UBRR0H = (unsigned int)Usart0.ubrr>>8;
	UBRR0L =(unsigned int)Usart0.ubrr;
	sei();
}
void usart0_sendchar(unsigned char data)
{
	UDR0 = data; 
    while ((UCSR0A & (1 << TXC0)) == 0);  
	UDR0 = '\n';
	while ((UCSR0A & (1 << TXC0)) == 0);
}
void usart0_sendint16(uint16_t data) 
{    
	UDR0 = data;
    while ((UCSR0A & (1 << UDRE0)) == 0);
	UDR0 = (data >> 8); 
    while ((UCSR0A & (1 << UDRE0)) == 0);
	UDR0 = '\n';
    while ((UCSR0A & (1 << UDRE0)) == 0);
}  
void usart0_sendstr(char *data)
{
    while (*data) {
        while ((UCSR0A & (1 << UDRE0)) == 0);
        UDR0 = *data; 
        data += 1;
    }
    while ((UCSR0A & (1 << UDRE0)) == 0);
    UDR0 = '\n';
}

ISR(USART0_RX_vect)
{
	Usart0.rdata = UDR0;
}