#ifndef	F_CPU
#define F_CPU	10000000UL
#endif

#include <avr/io.h>
#include "timers.h"
#include "system.h"

void timer1Init(void)
{
	TCCR1A = 0;
	TCCR1B = (1 << WGM12) | (1 << CS10);
	OCR1AH = 0x27; 
	OCR1AL = 0x10;
	TIMSK1 = 1 << OCIE1A;	
	
	SREG |= 0x80;	
}

void timer3Init(void)
{
	TCCR3A = 0;
	TCCR3B = (1 << WGM32) | (1 << CS30);
	OCR3AH = 0x2B;
	OCR3AL = 0x33;
	TIMSK3 = 1 << OCIE3A;
	
	SREG |= 0x80;
}

static unsigned int count = 0;

extern void CAN_CountTime(void);

ISR(TIMER1_COMPA_vect)
{
	CAN_CountTime();	
	countTime();
	debaunsingZaTaster();
}


ISR(TIMER3_COMPA_vect)
{
			
}