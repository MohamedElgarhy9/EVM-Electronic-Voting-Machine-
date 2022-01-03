/*
 * EVM.c
 *
 * Created: 12/30/2021 4:55:08 AM
 *  Author: Mohamed Maged 
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "BUTTON.h"
#define F_CPU 8000000UL
#include "util/delay.h"
int main(void)
{
	unsigned char count_A = 0;
	unsigned char count_B = 0;
	unsigned char count_C = 0;
	unsigned char count_D = 0;
	LCD_vInit();
	BUTTON_vInit('A',1);
	BUTTON_vInit('A',2);
	BUTTON_vInit('A',3);
	BUTTON_vInit('A',4);
	BUTTON_vInit('A',5);
	LCD_vSend_String("A:0");
	LCD_vMoveCursor(1,8);
	LCD_vSend_String("B:0");
	LCD_vMoveCursor(2,1);
	LCD_vSend_String("C:0");
	LCD_vMoveCursor(2,8);
	LCD_vSend_String("D:0");
	while(1)
	{
		if(BUTTON_u8Read('A',1) == 1)
		{
			// if the voter selects "A" candidate 
			count_A++; //no of votes that owned to candidate "A" will increase by one 
			LCD_vMoveCursor(1,3);
			if(count_A<10)
			{
				LCD_vSend_Char(count_A+48);	
			}
			//printing a number with two digits 
			else if(count_A<100 && count_A>9)
			{
				LCD_vSend_Char((count_A/10)+48);
				LCD_vSend_Char((count_A%10)+48);
			}
			//printing a number with three digits
			else if(count_A<1000 && count_A>99)
			{
				LCD_vSend_Char((count_A/100)+48);
				LCD_vSend_Char(((count_A/10)%10)+48);
				LCD_vSend_Char((count_A%10)+48);
			}
			_delay_ms(500);
		}
		else if(BUTTON_u8Read('A',2) == 1)
		{
			// if the voter selects "B" candidate 
			count_B++;//no of votes that owned to candidate "B" will increase by one
			LCD_vMoveCursor(1,10);
			if(count_B<10)
			{
				LCD_vSend_Char(count_B+48);
			}
			//printing a number with two digits
			else if(count_B<100 && count_B>9)
			{
				LCD_vSend_Char((count_B/10)+48);
				LCD_vSend_Char((count_B%10)+48);
			}
			//printing a number with three digits
			else if(count_B<1000 && count_B>99)
			{
				LCD_vSend_Char((count_B/100)+48);
				LCD_vSend_Char(((count_B/10)%10)+48);
				LCD_vSend_Char((count_B%10)+48);
			}
			_delay_ms(500);
		}
		else if(BUTTON_u8Read('A',3) == 1)
		{
			// if the voter selects "C" candidate 
			count_C++;//no of votes that owned to candidate "C" will increase by one
			LCD_vMoveCursor(2,3);
			if(count_C<10)
			{
				LCD_vSend_Char(count_C+48);
			}
			//printing a number with two digits
			else if(count_C<100 && count_C>9)
			{
				LCD_vSend_Char((count_C/10)+48);
				LCD_vSend_Char((count_C%10)+48);
			}
			//printing a number with three digits
			else if(count_C<1000 && count_C>99)
			{
				LCD_vSend_Char((count_C/100)+48);
				LCD_vSend_Char(((count_C/10)%10)+48);
				LCD_vSend_Char((count_C%10)+48);
			}
			_delay_ms(500);
		}
		else if(BUTTON_u8Read('A',4) == 1)
		{
			// if the voter selects "D" candidate 
			count_D++;//no of votes that owned to candidate "D" will increase by one
			LCD_vMoveCursor(2,10);
			if(count_D<10)
			{
				LCD_vSend_Char(count_D+48);
			}
			//printing a number with two digits
			else if(count_D<100 && count_D>9)
			{
				LCD_vSend_Char((count_D/10)+48);
				LCD_vSend_Char((count_D%10)+48);
			}
			//printing a number with three digits
			else if(count_D<1000 && count_D>99)
			{
				LCD_vSend_Char((count_D/100)+48);
				LCD_vSend_Char(((count_D/10)%10)+48);
				LCD_vSend_Char((count_D%10)+48);
			}
			_delay_ms(500);
		}
		//Reset part
		else if(BUTTON_u8Read('A',5) == 1)
		{
			//reset count_A, count_B, count_C and count_D
			count_A=count_B=count_C=count_D=0;
			LCD_vMoveCursor(1,5);
			LCD_vSend_Char(' ');
			LCD_vMoveCursor(1,4);
			LCD_vSend_Char(' ');
			//display zero on row one column three 
			LCD_vMoveCursor(1,3);
			LCD_vSend_Char(count_A+48);
			LCD_vMoveCursor(1,12);
			LCD_vSend_Char(' ');
			LCD_vMoveCursor(1,11);
			LCD_vSend_Char(' ');
			//display zero on row one column ten
			LCD_vMoveCursor(1,10);
			LCD_vSend_Char(count_B+48);
			LCD_vMoveCursor(2,5);
			LCD_vSend_Char(' ');
			LCD_vMoveCursor(2,4);
			LCD_vSend_Char(' ');
			//display zero on row two column three
			LCD_vMoveCursor(2,3);
			LCD_vSend_Char(count_C+48);
			LCD_vMoveCursor(2,12);
			LCD_vSend_Char(' ');
			LCD_vMoveCursor(2,11);
			LCD_vSend_Char(' ');
			//display zero on row two column ten
			LCD_vMoveCursor(2,10);
			LCD_vSend_Char(count_D+48);
			_delay_ms(1000);
		}
	}
}