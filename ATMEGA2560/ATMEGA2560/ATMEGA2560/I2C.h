/*
 * I2C.h
 *
 * Created: 9/9/2021 
 *  Author: asus
 */ 
#ifndef I2C_H_
#define I2C_H_
#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#define MAX_TRIES 50
#define twi_start	 0
#define twi_data 1
#define twi_stop 2
#define TWI_ARB_LOST 0x38
#define TWI_START 0x08
#define TWI_REP_START 0x10
#define TWI_SLA_ACK 0x18
#define TWI_SLA_NACK 0x20
#define TWI_DATA_ACK 0x28




// typedef enum I2C_Prescaler
// {
// 	I2C_Prescaler_BY_1 = 0x00,
// 	I2C_Prescaler_BY_4 = 0x01,
// 	I2C_Prescaler_BY_16 = 0x02,
// 	I2C_Prescaler_BY_64 = 0x03
// }I2C_Prescaler_t;


// typedef struct
// {
// 	volatile uint16_t SlaveAddress;
// 	
// 	
// }I2C_t;
// I2C_t I2C0;

void Twi_start(void);
unsigned char twi_tran(unsigned char type);
int twi_transmit_data(uint8_t twi_address,uint8_t data);
uint8_t twi_receive_data(uint8_t twi_address);
uint8_t read_data;
char *int_to_str(uint8_t num, uint8_t len);
#endif 