/*
 * Spi.h
 *
 * Created: 7/26/2021 3:15:23 PM
 *  Author: asus
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

typedef enum spiDataMode
{
	MODE0 = 0x00,
	MODE1 = 0x01,
	MODE2 = 0x02,
	MODE3 = 0x03
}spiDataMode_t;

typedef enum spiDivider
{
	BY_4 = 0x00,
	BY_16 = 0x01,
	BY_64 = 0x02,
	BY_128 = 0x03,
	BY_2 = 0x04,
	BY_8 = 0x05,
	BY_32 = 0x06
}spiDivider_t;

typedef enum spiMode
{
	SLAVE = 0x00,
	MASTER = 0x01
}spiMode_t;

typedef enum spiDataOrder
{
	MSBFIRST = 0x00,
	LSBFIRST = 0x01
}spiDataOrder_t;

typedef struct
{
	spiMode_t comMode;
	spiDivider_t divider;
	spiDataMode_t dataMode;
	spiDataOrder_t dataOrder;
	volatile uint8_t buffer[256];
	volatile uint16_t bufferIndex;
}spiDev_t;

spiDev_t SPI1;

void spiInit(void);
void spiInterrupt(bool flag);
void spiTransfer(uint8_t data);
void spiEnd(void);
uint16_t spiAvailable(void);
uint8_t* spiRead(uint16_t num);
void spiFlush(void);



#endif /* SPI_H_ */