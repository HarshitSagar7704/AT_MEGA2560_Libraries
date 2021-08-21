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


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Usart.h"
unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}
// ISR(USART0_RX_vect) {
// 	input_buffer[read_spot] = UDR0;
// 	usart0_sendint('A');
/*	_delay_ms(10);*/
// 	read_spot++;
// 	if(read_spot== 255) read_spot = 0;
//
int main()
{
	Usart0.baudrate = 9600;
	Usart0.Fosc = 16000000;
	Usart0.operatingMode = Normal;
	Usart0.usartMode = Asynchronous;
	Usart0.parityMode = Disabled;
	Usart0.stopBitSelect = bit_1;
	Usart0.characterSize = eight_bit;
	Usart0.clockPolarity = MODE0;
	Usar0tInit();
	/*usart0_get();*/
	
	while(1)
	{
		
		usart0_sendint('A');
		
		
	}
}


