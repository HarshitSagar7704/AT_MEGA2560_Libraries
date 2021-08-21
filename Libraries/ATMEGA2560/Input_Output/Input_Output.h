/*
 * Input_Output.h
 *
 * Created: 7/12/2021 1:44:11 PM
 *  Author: asus
 */ 


#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_
#include <avr/io.h>
#include <stdbool.h>
#define INPUT false
#define OUTPUT true
#define HIGH false
#define LOW true
void direction(uint8_t *port,uint8_t pin,bool dir);
void write(uint8_t *port,uint8_t pin,bool state);
int read(uint8_t portpin,uint8_t pin_no);
#endif /* INPUT_OUTPUT_H_ */