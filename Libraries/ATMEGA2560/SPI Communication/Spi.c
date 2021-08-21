/*
 * Spi.c
 *
 * Created: 7/26/2021 3:15:58 PM
 *  Author: asus
 */ 
#include "Spi.h"

void spiInit(void)
{
	cli();													//disable global interrupts before settings
	if(SPI1.comMode == MASTER)								//setting pin direction
	{
		DDRB = DDRB | 0x07;
		DDRB = DDRB & 0xF7;
		PORTB = PORTB & 0xF9;
		PORTB = PORTB | 0x01;
		spiInterrupt(false);
	}
	else
	{
		DDRB = DDRB | 0x08;
		DDRB = DDRB & 0xF8;
		spiInterrupt(true);
	}
	SPCR = 0x00;											//Writing 0x00 to the register before configuration
	SPSR = 0x00;											//Writing 0x00 to the register before configuration
	SPCR = SPCR | 0x40;										//enable SPI
	SPCR = SPCR | ((uint8_t)(SPI1.dataOrder) << 5);			//setting data order LSBFIRST/MSBFIRST
	SPCR = SPCR | ((uint8_t)(SPI1.comMode) << 4);			//setting Master/Salve mode
	SPCR = SPCR | ((uint8_t)(SPI1.dataMode) << 2);			//setting data mode CPOL and CPHA
	SPCR = SPCR | ((uint8_t)(SPI1.divider) & 0x03);			//setting clock rates
	SPSR = SPSR | (((uint8_t)(SPI1.divider) & 0x04) >> 2);  //setting clock rates
	
	SPI1.bufferIndex = 0;
	sei();													//enabling global interrupt
}

void spiInterrupt(bool flag)
{
	if(flag == true)
	SPCR = SPCR | 0x80;									//setting the interrupt flag
	else
	SPCR = SPCR & 0x7F;									//clearing the SPI interrupt flag
}

void spiTransfer(uint8_t data)
{
	PORTB = PORTB & 0xFE;									//pulling down the slave pin
	SPDR = data;		
	while(!(SPSR & (1<<SPIF)));									//loading SPDR register to start transmission	
	PORTB = PORTB | 0x01;
	SPI1.buffer[SPI1.bufferIndex]= SPDR;
	SPI1.bufferIndex++;								//setting busBusy flag, which will be cleared by interrupt handler
}

void spiEnd(void)
{
	cli();
	SPCR = SPCR & 0xBF;										//Disabling the SPI
	spiInterrupt(false);									//Disabling SPI interrupt
	sei();
}

uint16_t spiAvailable(void)
{
	return(SPI1.bufferIndex);								//return the buffer index
}

uint8_t* spiRead(uint16_t num)
{
	uint8_t *retVal,*temp;
	uint16_t i = 0;
	temp = (uint8_t*)calloc(num, sizeof(uint8_t));			//creating a dynamic memory of num numbers using calloc
	retVal = temp;											//assigning temp pointer to retVal pointer
	for(i=0; i<num; i++)
	{
		*temp = SPI1.buffer[SPI1.bufferIndex - 1];			//assigning last value of buffer to temp value
		temp++;												//increment the temp pointer
		SPI1.bufferIndex--;									//decrease the bufferIndex
	}
	return(retVal);											//return front pointer of the temp pointer
}
void spiFlush(void)
{
	SPI1.bufferIndex = 0;									//assigning bufferIndex to zero
}

