/*
 * EVM.h
 *
 * Created: 1/3/2022 9:44:37 PM
 *  Author: Mohamed Maged
 */ 


#ifndef EVM_H_
#define EVM_H_

#include <avr/io.h>
#include "LCD.h"
#include "BUTTON.h"
#define F_CPU 8000000UL
#include "util/delay.h"
void set_LCD(void);
void updateCounter(unsigned char *candidateCounter, unsigned char row, unsigned char col);

#endif /* EVM_H_ */