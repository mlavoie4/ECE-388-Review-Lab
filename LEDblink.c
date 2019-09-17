/*
    Created: 9/16/2019
    Author: Matt LaVoie
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int count = 2;
int Hz = 5;

int main(void)
{
    DDRB |= (1<<DDRB5);
	DDRB |= (0<<DDRB7);
	
	TCNT1 = -7812/Hz;														//Set Timer command Control Value to 1/240 sec
	TCCR1A |=(0b00<<COM1A0)|(0b00<<COM1B0)|(0b00<<WGM10);				//Sets Timer to Normal Mode
	TCCR1B |=(0b00<<WGM12)|(0b101<<CS10);								//Set TIMSKx so timer x interrupts a process
	TIMSK1 |=(0b1<<TOIE1);
	
	sei();

    while (1) 
    {
		 if ((PINB & (1 << 7)) == 0)
		 {
			 count++;
			 if (count > 3) count = 1;
			 while((PINB & (1 << 7)) == 0); 
			 
			 switch (count)
			 {
				 case 1: Hz = 1;
				 break;
				 case 2: Hz = 5;
				 break;
				 case 3: Hz = 10;
				 break;
			 }
		 }
    }
}

ISR(TIMER1_OVF_vect)
{
	switch (count)
	{
		case 1: Hz = 1;
		break;
		case 2: Hz = 5;
		break;
		case 3: Hz = 10;
		break;
	}
	PORTB = PORTB ^ 0b00100000;
	TCNT1 = -7812/Hz;
}
