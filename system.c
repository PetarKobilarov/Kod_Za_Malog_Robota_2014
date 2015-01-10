#ifndef F_CPU
#define F_CPU 10000000UL
#endif

#include "system.h"
#include "can.h"
#include "timers.h"
#include "detekcijaProtivnika.h"
#include "odometry.h"
#include <avr/io.h>
#include <util/delay.h>

static tSys robot;


void countTime(void)
{
	if(robot.matchStarted)
	{
		if(++robot.systemTime>=MATCHTIME)
		{
			if(robot.systemTime - 2000 >= MATCHTIME)
			{
				PORTF &= ~(1<<PINF0);
				while(1);
			}
			else
			{
				robot.theEnd=1;
				PORTG = 0xFF;
				PORTF |= (1 << PINF0);
			}
			//_delay_ms(2000);
			
		}
	}
}

void startMatch(void)
{
	robot.systemTime = 0;
	robot.theEnd = 0;
	robot.matchStarted = 1;
}

void setRobot( void )
{
		CAN_Init(4);
		timer1Init();
		
		DDRA = 0x00;
		PORTA = 0xFF;
		DDRB  &= ~(1<<PINB0);
		PORTB &= ~(1<<PINB0);
		DDRE &= ~(1<<PINE4);
		PORTE &= ~(1<<PINE4);
		DDRE &= ~(1<<PINE2);
		PORTE &= ~(1<<PINE2);
		DDRG = 0xFF;
		
		//while(jumperProvera() == 1) ;
		startMatch();
}