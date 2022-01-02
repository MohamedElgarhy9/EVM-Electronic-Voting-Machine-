/*
 * BUTTON.h
 *
 * Created: 10/5/2021 11:50:58 PM
 *  Author: Mohamed Maged
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void BUTTON_vInit(unsigned char portname,unsigned char pinnumber);//Set the direction of a given pin in a given port as input 
unsigned char BUTTON_u8Read(unsigned char portname,unsigned char pinnumber);//Read the value(zero/1) of a given pin in a given port
void BUTTON_vconnectInternalPULLUP(unsigned char portname,unsigned char pinnumber);//Connect the internal pull up for a given pin in a given port
void BUTTON_vdisconnectInternalPULLUP(unsigned char portname,unsigned char pinnumber);//Disconnect the internal pull up for a given pin in a given port

#endif /* BUTTON_H_ */