/*
 * EVM.c
 *
 * Created: 12/30/2021 4:55:08 AM
 *  Author: Mohamed Maged 
 */ 


#include "EVM.h"

int main(void)
{
	unsigned char count_A = 0;
	unsigned char count_B = 0;
	unsigned char count_C = 0;
	unsigned char count_D = 0;
	unsigned char row, col;
	LCD_vInit();
	BUTTON_vInit('A',1);
	BUTTON_vInit('A',2);
	BUTTON_vInit('A',3);
	BUTTON_vInit('A',4);
	BUTTON_vInit('A',5);
	set_LCD();
	while(1)
	{
		if(BUTTON_u8Read('A',1) == 1)
		{
			row=1, col=3;
			updateCounter(&count_A, row, col);
		}
		else if(BUTTON_u8Read('A',2) == 1)
		{
			row=1, col=10;
			updateCounter(&count_B, row, col);
		}
		else if(BUTTON_u8Read('A',3) == 1)
		{
			row=2, col=3;
			updateCounter(&count_C, row, col);
		}
		else if(BUTTON_u8Read('A',4) == 1)
		{
			row=2, col=10;
			updateCounter(&count_D, row, col);
		}
		//Reset part
		else if(BUTTON_u8Read('A',5) == 1)
		{
			//reset count_A, count_B, count_C and count_D
			count_A=count_B=count_C=count_D=0;
			LCD_vClearScreen();
			LCD_vMoveCursor(1,1);
			set_LCD();
			_delay_ms(1000);
		}
	}
}
void updateCounter(unsigned char *candidateCounter, unsigned char row, unsigned char col){
	// if the voter selects a candidate
	(*candidateCounter) ++; //no of votes that owned to the candidate will increase by one
	LCD_vMoveCursor(row,col);
	if(*candidateCounter<10)
	{
		LCD_vSend_Char((*candidateCounter)+48);
	}
	//printing a number with two digits
	else if((*candidateCounter)<100 && (*candidateCounter)>9)
	{
		LCD_vSend_Char(((*candidateCounter)/10)+48);
		LCD_vSend_Char(((*candidateCounter)%10)+48);
	}
	//printing a number with three digits
	else if((*candidateCounter)<1000 && (*candidateCounter)>99)
	{
		LCD_vSend_Char(((*candidateCounter)/100)+48);
		LCD_vSend_Char((((*candidateCounter)/10)%10)+48);
		LCD_vSend_Char(((*candidateCounter)%10)+48);
	}
	_delay_ms(500);
}
void set_LCD(void)
{
	LCD_vSend_String("A:0");
	LCD_vMoveCursor(1,8);
	LCD_vSend_String("B:0");
	LCD_vMoveCursor(2,1);
	LCD_vSend_String("C:0");
	LCD_vMoveCursor(2,8);
	LCD_vSend_String("D:0");
}

