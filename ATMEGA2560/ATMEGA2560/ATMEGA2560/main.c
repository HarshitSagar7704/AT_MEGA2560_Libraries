#define F_CPU 16000000
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "ADC.h"
int main(void)
{	DDRB |= (1 << PB0);
	voltage_Ref_S(AVCC);
	ADC_Prescaler(By_128);
	Adc(enable);
	uint16_t ADCValue = 145;
	while (1)
	{
		uint16_t read_value = ADC_Read()*0.4882;
		char val[4];                               
		itoa(read_value, val, 10);               
		int x = atoi(val);                    
		if(x > ADCValue)
		{
			PORTB |= (1 << PB0); 
		}
		else
		{
			PORTB &= ~(1 << PB0); 
		}
	}
}