/*
 * ADC.c
 *
 * Created: 18-11-2021 0:04:28
 *  Author: harsh
 */ 

#include "ADC.h"

void voltage_Ref_S(uint8_t Ref_bit)
{
	ADMUX = ADMUX | (uint8_t)((Ref_bit)<<6);
}
void ADC_Adjust_Result(uint8_t shift)
{
	ADMUX = ADMUX | (uint8_t)((shift)<<5);
}
void input_Ch_S(uint8_t chnl)
{
	ADMUX &= ~(0xE0); 
	ADMUX = ADMUX | (uint8_t)((chnl)&0x1F);
	ADCSRB = ADCSRB | (uint8_t)(((chnl)&0x20)>>2);
}
void ADC_Start_C()
{
	ADCSRA |= 0x40;
}
void Adc(uint8_t adc_state)
{
	if(adc_state==0x00)
	ADCSRA &= ~(0x80); 
	else if(adc_state==0x01)
	ADCSRA = ADCSRA | (uint8_t)((adc_state)<<7); 
	
}
void ADC_AT(uint8_t AT_state)
{
	if(AT_state==0x00)
	ADCSRA &= ~(0x20); 
	else if(AT_state==0x01)
	ADCSRA = ADCSRA | (uint8_t)((AT_state)<<5);
}
void ADC_InF(uint8_t Inf_state)
{
	if(Inf_state==0x00)
	ADCSRA &= ~(0x10);
	else if(Inf_state==0x01)
	ADCSRA = ADCSRA | (uint8_t)((Inf_state)<<4);
}
void ADC_In(uint8_t In_state)
{
	if(In_state==0x00)
	ADCSRA &= ~(0x08);
	else if(In_state==0x01)
	ADCSRA = ADCSRA | (uint8_t)((In_state)<<3);
}
void ADC_Prescaler(uint8_t adc_Prescaler)
{
	ADCSRA &= ~(0x07);
	ADCSRA |= (uint8_t)(adc_Prescaler);
}
void ADC_AutoTrigger_Source(uint8_t ADC_ATS)
{
		ADCSRB &= ~(0x07);
		ADCSRB |= (uint8_t)(ADC_ATS);
}
// void Digital_Input_Disable(uint16_t ADC_ID)
// {
// 	
// }




