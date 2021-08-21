/*
 * Usart.h
 *
 * Created: 8/7/2021 1:49:46 PM
 *  Author: asus
 */ 


#ifndef USART_H_
#define USART_H_
#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

typedef enum UsartMode
{
	Asynchronous = 0x00,
	Synchronous = 0x01,
	Master_SPI = 0x03
}UsartMode_t;

typedef enum ParityMode
{
	Disabled = 0x00,
	Reserved = 0x01,
	Enable_Even = 0x02,
	Enable_Odd = 0x03
}ParityMode_t;

typedef enum StopBitSelect
{
	bit_1 = 0x00,
	bit_2 = 0x01
}StopBitSelect_t;

typedef enum CharacterSize
{
	five_bit = 0x00,
	six_bit = 0x01,
	seven_bit = 0x02,
	eight_bit = 0x03,
	nine_bit = 0x07
}CharacterSize_t;

typedef enum ClockPolarity
{	
	MODE0 = 0x00,
	MODE1 = 0x01
}ClockPolarity_t;

typedef enum OperatingMode
{
	Normal = 0x00,
	Double = 0x01,
	Master = 0x00
} OperatingMode_t;
typedef enum spiDataMode
{
	SPI_MODE0 = 0x00,
	SPI_MODE1 = 0x02,
	SPI_MODE2 = 0x01,
	SPI_MODE3 = 0x03
}spiDataMode_t;

typedef struct
{
	UsartMode_t usartMode;
	ParityMode_t parityMode;
	StopBitSelect_t stopBitSelect; 
	CharacterSize_t characterSize;
	ClockPolarity_t clockPolarity;
	OperatingMode_t operatingMode;
	spiDataMode_t spiDatamode;
	volatile uint16_t ubrr;
	volatile uint16_t baudrate;
	volatile uint32_t Fosc;
	
}UsartDev_t;
UsartDev_t Usart0;
UsartDev_t Usart1;
UsartDev_t Usart2;
UsartDev_t Usart3;
void Usar0tInit(void);
void usart0_sendint(uint8_t data);
void usart0_sendint16(uint16_t data);
void usart0_sendstr(char *data);
#endif /* USART_H_ */