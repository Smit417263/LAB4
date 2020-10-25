/*	Author: spate130
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char counter = 0x00; 
    /* Insert your solution below */
    while (1) {
	tempA = PINA;
	tempB = PINB;

	for(int i = 0; i < 7; ++i){
		if(((tempA & (0x01 << i))!= 0)){
			counter = counter + 1;
		}
	}

	for(int i = 0; i < 7; ++i){
		if(((tempB & (0x01 << i))!= 0)){
			counter = counter + 1;
		}
	}

	PORTC = counter;
    }
    return 1;
}
