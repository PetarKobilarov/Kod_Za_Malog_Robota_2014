#ifndef F_CPU
#define F_CPU 10000000UL
#endif

#include "can.h"
#include "odometry.h"
#include <util/delay.h>
#include <avr/io.h>
#include "system.h"
#include "detekcijaProtivnika.h"
#include "crvena-zutaStrana.h"

void stop(void)
{
	unsigned char message[8];
	
	message[0] = 'S';
	
	while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));	
	_delay_ms(50);
}

void setSpeed(unsigned char Brzina)
{
	unsigned char message[8];
	
	message[0] = 'V';
	message[1] = Brzina;
	
	while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));	
	_delay_ms(50);
}

unsigned int moveOnDirection( signed int razdaljina, unsigned char brzina, int tipKretanja )
{
	unsigned char message[8];
	char smer = 0;
	
	setSpeed(brzina);
	
	message[0] = 'D';
	message[1] = razdaljina >> 8;
	message[2] = razdaljina;
	message[3] = 0;
	
	while (CAN_Write(message,DRIVER_TX_IDENTIFICATOR));	
	_delay_ms(10);
	
	if( razdaljina > 0 )
		smer =  1;
	else
		smer = -1; 
	
	while(1)
	{
		_delay_ms(120);
		if( tipKretanja == STANDARD )
		{
			if ( dobiDetekciju( smer ) )
			{
				stop();
				_delay_ms(1000);
				return 2;
			}
		}
		else if( tipKretanja == PORAVNAVANJE)
		{
			//Ubaciti kod za poravnavanje
		}
		
		message[0] = 'P';
		while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
		_delay_ms(10);
		
		while(CAN_CheckRX(DRIVER_RX_IDENTIFICATOR) == 0)
		{
			_delay_ms(5);
			CAN_Read(message, DRIVER_RX_IDENTIFICATOR,0);
			
			if (message[0] == 'I')
			{
				stop();
				return KRETNJE_ZAVRSENO;
			}
			else if (message[0] == 'S')
			{
				stop();
				return ZAGLAVLJEN;
			}
			else if (message[0] == 'E')
			{
				stop();
				return NEDEFINISANO;
			}
			else if (message[0] == 'R')
			{
				continue;
			}
		}
	}
}

char gotoXY( unsigned int X, unsigned int Y, unsigned char brzina, signed char smer, int tipKretanja )
{
	unsigned char message[8];
	
	setSpeed( brzina );
	
	message[0] = 'G';
	message[1] = X >> 8;
	message[2] = X;
	message[3] = Y >> 8;
	message[4] = Y;
	message[5] = 0;
	message[6] = smer;
	
	while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
	_delay_ms(10);
	
	while(1)
	{	
		_delay_ms(120);
		if( tipKretanja == STANDARD )
		{
			if ( dobiDetekciju( smer ) )
			{
				stop();
				_delay_ms(10);
				return DETEKTOVAN;
			}
		}
		else if ( tipKretanja == PORAVNAVANJE )
		{
			//Ubaciti kod za kretanje
		}
		
		message[0] = 'P';
		while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
		_delay_ms(60);
		
		while(CAN_CheckRX(DRIVER_RX_IDENTIFICATOR) == 0 )
		{
			_delay_ms(5);
			CAN_Read(message, DRIVER_RX_IDENTIFICATOR,0);
			
			if (message[0] == 'I')
			{
				stop();
				return KRETNJE_ZAVRSENO;
			}
			if (message[0] == 'S')
			{
				stop();
				return ZAGLAVLJEN;
			}
		
			if (message[0] == 'E')
			{
				stop();
				return NEDEFINISANO;
			}			
		}		
	}
}

unsigned int rotate( signed int ugao, unsigned char brzina )
{
	unsigned char message[8];
	
	setSpeed( brzina );
	
	message[0] = 'T';
	message[1] = ugao >> 8;
	message[2] = ugao;

	while( CAN_Write(message,DRIVER_TX_IDENTIFICATOR) );
	_delay_ms(50);
		
			message[0] = 'P';
			while( CAN_Write(message,DRIVER_TX_IDENTIFICATOR) );
			_delay_ms(50);
			
			while( CAN_CheckRX(DRIVER_RX_IDENTIFICATOR) == 0 )
			{
				_delay_ms(10);
				CAN_Read( message, DRIVER_RX_IDENTIFICATOR,0 );
				
				if ( message[0] == 'I' )
				{
					return KRETNJE_ZAVRSENO;
				}
				
				if ( message[0] == 'S' )
				{
					return ZAGLAVLJEN;
				}
				
				if ( message[0] == 'E' )
				{
					return NEDEFINISANO;
				}
			}
}

unsigned int setUgao( signed int apsolutniUgao, unsigned char brzina )
{
	unsigned char message[8];
	
	setSpeed( brzina );
	
	message[0] = 'A';
	message[1] = apsolutniUgao >> 8;
	message[2] = apsolutniUgao;
	
	_delay_ms(50);
	while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
	_delay_ms(50);
	
		message[0] = 'P';
		while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
		_delay_ms(50);
		
		while(CAN_CheckRX(DRIVER_RX_IDENTIFICATOR) == 0 )
		{
			_delay_ms(5);
			CAN_Read(message, DRIVER_RX_IDENTIFICATOR,0);
			
			if (message[0] == 'I')
			{
				return KRETNJE_ZAVRSENO;
			}
			
			if (message[0] == 'S')
			{
				return ZAGLAVLJEN;
			}
			
			if (message[0] == 'E')
			{
				return NEDEFINISANO;
			}
		}	
}

unsigned int setPosition ( unsigned int X, unsigned int Y, signed int smer )
{
	unsigned char message[8];
		
	message[0] = 'I';
	message[1] = X >> 8;
	message[2] = X;
	message[3] = Y >> 8;
	message[4] = Y;
	message[5] = smer >> 8;
	message[6] = smer;
	
	
	while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
	_delay_ms(50);
		
	return 1;
}

char getY(void)
{
	unsigned char message [8];
	unsigned char yPosition = 0;
	while(1)
	{
		_delay_ms(100);
		message[0] = 'P';
		while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
		
		if(CAN_CheckRX(DRIVER_RX_IDENTIFICATOR))
		{
			CAN_Read(message, DRIVER_RX_IDENTIFICATOR,0);
			yPosition = message[3] << 8;
			yPosition |= message[4];
			return yPosition;
			
		}
	}
	
}

char getX(void)
{
	unsigned char message [8];
	unsigned char xPosition = 0;
	while(1)
	{
		_delay_ms(100);
		message[0] = 'P';
		while(CAN_Write(message,DRIVER_TX_IDENTIFICATOR));
		
		if(CAN_CheckRX(DRIVER_RX_IDENTIFICATOR))
		{
			CAN_Read(message, DRIVER_RX_IDENTIFICATOR,0);
			xPosition = message[1] << 8;
			xPosition |= message[2];
			return xPosition;
			
		}
	}
	
}