#define F_CPU 16000000

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <math.h>
void delay(int t);
uint8_t a = 11/7;
uint8_t b;

int main()
{
	sei();
	uint8_t brightness = 0;
	DDRB |= (1<<5);
	TCCR1A |= (1<<WGM10)| (1<<WGM11)| (1<<COM1A1);
	TCCR1B |= (1<<CS10);
	while(1)
	{	
		b = sin(11/7);
		if(b==0)
		{

		for(brightness=255;brightness>0;brightness--)
		{
			OCR1A = brightness;
			_delay_ms(10); 
		}
		brightness = 255;
			
		}		
// 		for(brightness=255;brightness>0;brightness--)
// 		{
// 			OCR1A = brightness;
// 			_delay_ms(10);
// 		}
	}
}
// ISR(TIMER1_COMPA_vect)
// {
// 	
// 	PORTD &= ~(1<<7);
// 	/*TCNT1 = 0;*/
// }
// ISR(TIMER1_OVF_vect)
// {
// 	PORTD &= ~(1<<7);
// 	PORTD |= (1<<7);
// }
/*
void delay(int t)
{
	t=t*61;
	for(int i=0;i<t;i++)
	{
		TCNT0 = 00;
		while((TIFR0 & (1<<TOV0))==0);
		TIFR0 = (1<<TOV0);
	}
	t=0;
} 
int main()
{
	sei();
	DDRD |= (1<<7);
	TCCR1B |= (1<<CS12)| (1<<CS10)|(1<<WGM02);
	TIMSK1 |= (1<<OCIE1A);
	OCR1A = 15625;
	while(1)
	{
		delay(5);
	}
}
ISR(TIMER1_COMPA_vect)
{
	PORTD ^= (1<<7);
	TCNT1 = 0;
} */