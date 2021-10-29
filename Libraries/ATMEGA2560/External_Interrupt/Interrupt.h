/*
 * Interrupt.h
 *
 * Created: 7/12/2021 3:17:06 PM
 *  Author: asus
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include <avr/io.h>
#include <avr/interrupt.h>
enum SenseControl{lowerLevel=0,anyLogic=1,falling=2,rising=3} Sense;
enum intr {Int0=0,Int1=1,Int2=2,Int3=3,Int4=4,Int5=5,Int6=6,Int7=7} interrupt;
void interruptDisable(uint8_t interrupt);
void interruptEnable(uint8_t interrupt,uint8_t Sense);




#endif /* INTERRUPT_H_ */