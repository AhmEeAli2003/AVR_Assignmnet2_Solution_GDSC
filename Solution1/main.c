/*
 * main.c
 *
 *  Created on: ٢١‏/٠٤‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "STD_TYPES.h"
#include <util/delay.h>

#define DDRA	*((volatile u8*) 0x3A)
#define PORTA	*((volatile u8*) 0x3B)
#define PINA    *((const volatile u8*) 0x39)

#define DDRB	*((volatile u8*) 0x37)
#define PORTB	*((volatile u8*) 0x38)
#define PINB    *((const volatile u8*) 0x36)

/*
 *	Requirements:
		•The Led 1 & 2 is connected to pin 0 & 1 in PORTA.
		• The switch 1 , 2 , 3 is connected to pin 0 & 1 & 2 in PORTB.
		• If switch 1 is pressed just turn on the first led1 only , if switch 2 is pressed just turn on led2 only , if switch 3 is pressed turn on the 2 leds .
		• In case no switches are pressed both leds are off.
 */

int main(void)
{
	DDRA |= (1<<0) | (1<<1); //Set PINA0 & PINA1 [output].
	DDRB &= ~(1<<0) & ~(1<<1) & ~(1<<2); //Clear PINB0,1&2 [Input].

	PORTA &= ~(1<<0) & ~(1<<1); //Turn off LEDs.
	PORTB |= (1<<0) | (1<<1)  | (1<<2); //Enable internal pull up.

	while(1)
	{
		if(((PINB >> 0) & 0x01) == 0)
		{
			PORTA |= (1<<0);
		}
		else
		{
			PORTA &= ~(1<<0);
		}

		if(((PINB >> 1) & 0x01) == 0)
		{
			PORTA |= (1<<1);
		}
		else
		{
			PORTA &= ~(1<<1);
		}
		if(((PINB >> 2) & 0x01) == 0)
		{
			PORTA |= (1<<0) | (1<<1);
		}
		else
		{
			PORTA &= ~(1<<0) & ~(1<<1);
		}
	}
}


