#ifndef TIMER_H_
#define TIMER_H_
#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

typedef enum compareOutputMode
{
	COMODE0_A = 0x00,
	COMODE1_A = 0x01,
	COMODE2_A = 0x02,
	COMODE3_A = 0x03,
	COMODE0_B = 0x00,
	COMODE1_B = 0x01,
	COMODE2_B = 0x02,
	COMODE3_B = 0x03
}compareOutputMode_t;
typedef enum timerN
{
	timer0= 0,
	timer1 = 1,
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
typedef enum state
{
	Disable = 0x00,
	Enable = 0x01
}state_t;
typedef struct
{
	compareOutputMode_t CompareOutputMode;
	waveformGenerationMode_t WaveformGenerationMode;
	clockSelectBit_t ClockSelectBit;
}timer_t;

void Timer_init(uint8_t timerNo,uint8_t clockSB,uint8_t waveformGM,uint8_t compareOM);
void Timer_InterruptEnableMask(uint8_t timerNo,uint8_t OCIE_A,uint8_t OCIE_B,uint8_t TOCIE);
#endif /* TIMER_H_ */