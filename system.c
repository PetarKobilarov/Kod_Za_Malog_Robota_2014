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

char setServo( signed int position, unsigned char channel )	
{
	
	unsigned char message[8];
	int pwm;
	
	//if(channel == SERVO_STISKAC)
	pwm = 2074 + ((double)position / 90) * 700 * 1.5;
	//else if(channel == SERVO_VRATA)
	//pwm = 1000 + ((double)position / 90) * 600;
	
	message[0] = 'D';
	message[1] = pwm >> 8;
	message[2] = pwm;
	message[3] = channel;
	
	while(CAN_Write(message,KINEZ_TX_IDENTIFICATOR))
		_delay_ms(10);
	
	if(CAN_CheckRX(KINEZ_RX_IDENTIFICATOR))
	{	_delay_ms(5);
		CAN_Read(message, KINEZ_RX_IDENTIFICATOR, 100);
		_delay_ms(5);
		if(message[0] != 'Q')
		return 1;
		else
		return 0;
	}
}

char setAx( unsigned int position, unsigned int speed,unsigned char id )	/*AX servo ID = 2*/
{
	unsigned char message[8];
	
	message[0] = 'I';
	message[1] = position >> 8;
	message[2] = position;
	message[3] = speed >> 8;
	message[4] = speed;
	message[5] = id;
	message[6] = 0;
	message[7] = 0;
	
	while(CAN_Write(message,DRIVER_LIFT_TX_IDENTIFICATOR))
	_delay_ms(10);
	
	if(CAN_CheckRX(DRIVER_LIFT_RX_IDENTIFICATOR))
	{
		CAN_Read(message, DRIVER_LIFT_RX_IDENTIFICATOR, 100);
		
		if(message[0] != 'X')
		return 1;
		else
		return 0;
	}
	
	return 1;
}

void countTime( void )
{
	if(robot.matchStarted)
	{
		robot.systemTime++;
		if(robot.systemTime>=MATCHTIME)
		{
			robot.theEnd=1;
			PORTG = 0xFF;
			while(1);
		}
	}
}

void startMatch( void )
{
	robot.systemTime = 0;
	robot.theEnd = 0;
	robot.matchStarted = 1;
	robot.pisaj = 0;
}

void setRobot( void )
{
	CAN_Init(4);
	
	timer1Init();
	timer3Init();
	
	DDRA = 0x00;
	PORTA = 0xFF;
	
	DDRB = 0x00;
	PORTB = 0xFF;
	
	DDRE = 0x00;
	PORTE = 0xFF;
	
	DDRG = 0xFF;
	
	DDRF = 0x00;
	PORTF = 0xFF;
	
	//while(jumperStartRobotProvera());
	startMatch();
}