#include "Timer.h"
void Timer_init(uint8_t timerNo,uint8_t clockSB,uint8_t waveformGM,uint8_t compareOM)
{
	switch(timerNo)
	{
		case 0:
		TCCR0B |= (uint8_t)clockSB;
		TCCR0A |= (uint8_t)waveformGM;
		TCCR0A |= (((uint8_t)compareOM)<<6);
		break;
		case 1:
		TCCR1B |= (uint8_t)clockSB;
		TCCR1A |= (uint8_t)waveformGM;
		TCCR1A |= (((uint8_t)compareOM)<<6);		
		break;
	}
}
void Timer_InterruptEnableMask(uint8_t timerNo,uint8_t OCIE_A,uint8_t OCIE_B,uint8_t TOCIE)
{
	switch(timerNo)
	{
		case 0:
		TIMSK0 |= ((uint8_t)OCIE_A<<1);
		TIMSK0 |= ((uint8_t)OCIE_B<<2);
		TIMSK0 |= (uint8_t)TOCIE;
		break;
		case 1:
// 		TCCR1B |= (uint8_t)clockSB;
// 		TCCR1A |= (uint8_t)waveformGM;
// 		TCCR1A |= (((uint8_t)compareOM)<<6);
		break;
}
}