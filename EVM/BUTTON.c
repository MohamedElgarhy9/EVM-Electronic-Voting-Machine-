/*
 * BUTTON.c
 *
 * Created: 10/5/2021 11:43:38 PM
 *  Author: Mohamed Maged
 */ 

#include "DIO.h"

void BUTTON_vInit(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPINDIR(portname,pinnumber,0); //Set the direction of a given pin in a given port as input 
}
unsigned char BUTTON_u8Read(unsigned char portname,unsigned char pinnumber)
{
	return DIO_u8readPIN(portname,pinnumber); //Read the value(zero/1) of a given pin in a given port
}
void BUTTON_vconnectInternalPULLUP(unsigned char portname,unsigned char pinnumber)
{
	DIO_vconnectInternalPULLUP(portname,pinnumber,1); //Connect the internal pull up for a given pin in a given port
}
void BUTTON_vdisconnectInternalPULLUP(unsigned char portname,unsigned char pinnumber)
{
	DIO_vconnectInternalPULLUP(portname,pinnumber,0); //Disconnect the internal pull up for a given pin in a given port
}