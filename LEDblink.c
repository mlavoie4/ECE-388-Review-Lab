/*
    Created: 9/16/2019
    Author: Matt LaVoie
*/

#define F_CPU 16000000UL //Set the clock frequency
#include <avr/io.h> //call IO library
#include <util/delay.h> //call delay library

int main(void)
{
    DDRB |= (1<<DDB5); //Set Port B 5 or PB5 or PCINT5 or pin 17 to output (1 is output and 0 is input)
    while(1)
    {
        /*
        PORTB |= (1<<PORTB5);    //Set PB5 to 1 which is high (LED on)
        _delay_ms(1000);        //Delay for 1000ms or 1 sec
        PORTB &= ~(1<<PORTB5);    //Set PB5 to 0 which is low (LED off)
        _delay_ms(1000);        //Delay for 1000ms or 1 sec
        */
        PINB |= (1<<PINB5);
        _delay_ms(1000);        //Delay for 1000ms or 1 sec
    }
}
