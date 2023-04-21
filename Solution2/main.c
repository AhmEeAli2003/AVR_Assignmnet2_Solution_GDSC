/*
 * main.c
 *
 *  Created on: ٢١‏/٠٤‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "STD_TYPES.h"

#define DDRA	*((volatile u8*) 0x3A)
#define PORTA	*((volatile u8*) 0x3B)
#define PINA    *((const volatile u8*) 0x39)

#define DDRB	*((volatile u8*) 0x37)
#define PORTB	*((volatile u8*) 0x38)
#define PINB    *((const volatile u8*) 0x36)

/*
 * Write Embedded c code to control a 7-segment using two push buttons.      ( 10 points)
	Requirements:
 	 • The two switches are connected to pin 0 & 1 in PORTA.
	 • If the switch1 is pressed just increase the number appeared in the 7 segment display, and if the number reach the maximum number (9) do nothing.
	 • If the switch2 is pressed just decrease the number appeared in the 7 segment display, and if the number reach the minimum number (0) do nothing.
 *
 */

int main(void)
{
	u8 common_cathode_numbers_arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
									   0x6D, 0x7D, 0x07, 0x7F, 0x6F
									  }, counter = 0;
	DDRA &= ~(1<<0) & ~(1<<1); //Clear PINA0 & PINA1 [Input].
	PORTA |= (1<<0) | (1<<1);  //Enable internal pull up.

	DDRB = 0xff;  //Set PORTB as output.
	PORTB = 0x00; //Turn off SSD [Seven Segment Display].

	while(1)
	{
		if(counter >= 0 && counter <= 9)
		{
			if(((PINA >> 0) & 0x01) == 0)
			{
				if(counter != 9)
				{
					counter++;
				}
				while(((PINA >> 0) & 0x01) == 0); //Value doesn't appear Except after Release switch.
			}

			if(((PINA >> 1) & 0x01) == 0)
			{
				if(counter != 0)
				{
					counter--;
				}
				while(((PINA >> 1) & 0x01) == 0);
			}
		}

		PORTB = common_cathode_numbers_arr[counter];
	}

	return 0;
}


