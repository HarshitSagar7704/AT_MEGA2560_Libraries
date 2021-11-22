/*
 * ADC.h
 *
 * Created: 18-11-2021 0:04:14
 *  Author: harsh
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

typedef enum VoltageReferenceBit
{
	AREF = 0x00,
	AVCC = 0x01,
	Internal_1_1 = 0x02,
	Internal_2_56 = 0x03
}VoltageReferenceBit_t;

typedef enum AdcAdjustResult
{
	right = 0x00,
	left = 0x01	
}AdcAdjustResult_t;

typedef enum InputChS
{
	ADC0 = 0x00,
	ADC1 = 0x01,
	ADC2 = 0x02,
	ADC3 = 0x03,
	ADC4 = 0x04,
	ADC5 = 0x05,
	ADC6 = 0x06,
	ADC7 = 0x07,
	ADC8 = 0x20,
	ADC9 = 0x21,
	ADC10 = 0x22,
	ADC11 = 0x23,
	ADC12 = 0x24,
	ADC13 = 0x25,
	ADC14 = 0x26,
	ADC15 = 0x27	
}InputChS_t;
typedef enum State
{
	disable = 0x00,
	enable = 0x01	
}State_t;
typedef enum ADCPrescaler
{
	By_2 = 0x01,
	By_4 = 0x02,
	By_8 = 0x03,
	By_16 = 0x04,
	By_32 = 0x05,
	By_64 = 0x06,
	By_128 = 0x07,
}ADCPrescaler_t;
typedef enum AdcAutoTriggerSource
{
	FreeRunning = 0x00,
	AnalogComparator = 0x01,
	ExternalInterruptRequest_0 = 0x02,
	TimerCounter0CompareMatchA = 0x03,
	TimerCounter0Overflow = 0x04,
	TimerCounter1CompareMatchB = 0x05,
	TimerCounter1Overflow = 0x06,
	TimerCounter1CaptureEvent = 0x07	
}AdcAutoTriggerSource_t;
void voltage_Ref_S(uint8_t Ref_bit);
void ADC_Adjust_Result(uint8_t shift);
void input_Ch_S(uint8_t chnl);
void ADC_Start_C();
void Adc(uint8_t adc_state);
void ADC_AT(uint8_t AT_state);
void ADC_InF(uint8_t Inf_state);
void ADC_In(uint8_t In_state);
void ADC_Prescaler(uint8_t adc_Prescaler);
void ADC_AutoTrigger_Source(uint8_t ADC_ATS);
/*void Digital_Input_Disable(uint16_t ADC_ID);*/

#endif /* ADC_H_ */