/*
 * GccApplication1.c
 *
 * Created: 7/5/2021 5:52:18 PM
 * Author : asus
 */ 


// #define F_CPU 16000000L
// #include "Spi.h"
// #include <avr/io.h>
// #include <util/delay.h>
// #include <avr/interrupt.h>
// ISR(SPI_STC_vect)
// {
// 	SPI1.buffer[SPI1.bufferIndex] = SPDR;
// 	SPI1.bufferIndex++;
// }
// int main()
// {
// 
// 	SPI1.comMode = MASTER;
// 	SPI1.divider = BY_8;
// 	SPI1.dataMode = MODE0;
// 	SPI1.dataOrder = MSBFIRST;
// 	uint8_t i;
// 	spiInit();
// 	 spiFlush();
// 	 for( i=0;i<2;i++)
// 	 {
// 		 spiTransfer(0x00);
// 		 _delay_ms(1000);
// 	 }
// 	 
// 	 uint8_t* temp;
// 	 spiTransfer(spiAvailable());
// 	 uint8_t a,b,c,d,e;
//  	 a=SPI1.buffer[0];
// 	  
// 	 b=SPI1.buffer[1];
// // 	 c=SPI1.buffer[2];
// // 	 d=SPI1.buffer[3];
// // 	 e=SPI1.buffer[4];
// 	 spiTransfer(a);
// 	 _delay_ms(10);
// 	 spiTransfer(b);
// 	 _delay_ms(10);
// // 	 spiTransfer(c);
// // 	 _delay_ms(10);
// // 	 spiTransfer(d);
// // 	 _delay_ms(10);
// // 	 spiTransfer(e);
// // 	 _delay_ms(10);
// 	 
// // 	 temp = spiRead(5);
// // 	 for(i=0;i<5;i++)
// // 	 {
// // 		 
// // 		 spiTransfer(*temp);
// // 		 _delay_ms(1000);
// // 		 temp++;
// // 	 }
// 	 while(1);
// }


// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include <avr/interrupt.h>
// #include "Usart.h"
// int main()
// {
// 	Usart0.baudrate = 9600;
// 	Usart0.Fosc = 16000000;
// 	Usart0.operatingMode = Normal;
// 	Usart0.usartMode = Asynchronous;
// 	Usart0.parityMode = Disabled;
// 	Usart0.stopBitSelect = bit_1;
// 	Usart0.characterSize = eight_bit;
// 	Usart0.clockPolarity = MODE0;
// 	Usart0.rdata = 'A';
// 	Usar0tInit();
// 	while(1)
// 	{
// 		usart0_sendchar(Usart0.rdata);
// 		_delay_ms(500);
// 	}
// }
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include <avr/interrupt.h>
// #include "I2C.h"
// 
// int main()
// {
// 	DDRE |= 0x0B;
// 	PORTE |=0x0B;
// 	_delay_ms(1000);
// 	PORTE &=!(0x0B);
// 	/*I2C_Prescaler_BY_1;*/
// 	I2C0.SlaveAddress = 8;
// 	uint8_t data = 0x02;
// 	TWSR = 0x00;
// 	TWBR = (F_CPU / 100000UL - 16) / 2;
// 	while(1)
// 	{
// 		TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
// 		while(!(TWCR&(1<<TWINT)));
// 		if((TWSR & 0xF8)!= 0x08)
// 		{
// 			PORTE |=0x02;
// 			_delay_ms(4000);
// 			PORTE &=!(0x02);
// 		}
// 		TWDR = 8;
// 		TWCR = (1<<TWINT)|(1<<TWEN);
// 		while(!(TWCR&(1<<TWINT)));
// 		if((TWSR & 0xF8)!= 0x18 )
// 		{
// 			PORTE |=0x08;
// 			_delay_ms(4000);
// 			PORTE &=!(0x08);
// 		}
// 		TWDR = data;// Entering data for transmission.
// 		TWCR = (1<<TWINT)|(TWEN);
// 		while(!(TWCR&(1<<TWINT)));
// 		if((TWSR & 0xF8)!=0x28)
// 		{
// 			PORTE |=0x01;
// 			_delay_ms(1000);
// 			PORTE &=!(0x01);
// 		}
// 		data++;
// 		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
// 		
// 		}
// }
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "I2C.h"
#include "Usart.h"
int main() 
{
	Twi_start();
	char a=0;
	Usart0.baudrate = 9600;
	Usart0.Fosc = 16000000;
	Usart0.operatingMode = Normal;
	Usart0.usartMode = Asynchronous;
	Usart0.parityMode = Disabled;
	Usart0.stopBitSelect = bit_1;
	Usart0.characterSize = eight_bit;
	Usart0.clockPolarity = MODE0;
	Usart0.rdata = 'A';
	Usar0tInit();
	read_data = 0;
	while(1)
{	
		twi_receive_data(0b10000011);
		a=int_to_str(read_data,2);
		usart0_sendchar(a);
		_delay_ms(1);
	}
}
// int main()
// {
// 	Twi_start();
// 	unsigned int p=0;
// 	while(1)
// 	{for (unsigned int i = 0;i<6;i++)
// 		{
// 			twi_transmit_data(0b00000000,p);
// 			_delay_ms(1000);
// 			p++;
// 		}
// 		p=0;
// 		for (unsigned int i = 0;i<9;i++)
// 		{
// 			twi_transmit_data(0b00000010,p);
// 			_delay_ms(1000);
// 			p++;
// 		}
// 		p=0;
// 	}
// }