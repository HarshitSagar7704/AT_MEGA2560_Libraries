#ifndef SPI_H_
#define SPI_H_
#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

typedef enum compareOutputMode
{
	MODE0 = 0x00,
	MODE1 = 0x01,
	MODE2 = 0x02,
	MODE3 = 0x03
}compareOutputMode_t;
typedef enum timerN
{
	timer0= 1,
	timer1 = 2,
	timer2 = 3,
	timer3= 4,
	timer4= 5,
	timer5= 6
}timerN_t;

typedef enum waveformGenerationMode
{
	Normal= 0x00,
	PhaseCorrect_TM = 0x01,
	CTC = 0x02,
	FastPWM_TM = 0x03,
	PhaseCorrect_OCR = 0x05,
	FastPWM_OCR = 0x07,
}waveformGenerationMode_t;
typedef enum clockSelectBit
{
	TC_stop = 0x00,
	noPrescale = 0x01,
	BY_8 = 0x02,
	BY_64 = 0x03,
	BY_256 = 0x04,
	BY_1024 = 0x05,
	ExClkOnFalling = 0x06,
	ExClkOnRising = 0x07
}clockSelectBit_t; 
typedef struct
{
	compareOutputMode_t CompareOutputMode;
	waveformGenerationMode_t WaveformGenerationMode;
	clockSelectBit_t ClockSelectBit;
	timerN_t TimerN;
}timer_t;
// timer_t T0;
// timer_t T1;
// timer_t T2;
// timer_t T3;
// timer_t T4;
// timer_t T5;
void Timer0_init(uint8_t timerNo, compareOM,uint8_t waveformGM,uint8_t clockSB);
#endif /* SPI_H_ */