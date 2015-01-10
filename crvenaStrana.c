#ifndef F_CPU
#define F_CPU 10000000UL
#endif

#include <avr/pgmspace.h>
#include <util/delay.h>
#include "system.h"
#include "odometry.h"
#include "timers.h"
#include "detekcijaProtivnika.h"
#include "crvena-ZutaStrana.h"

/*****************************************************************************POZICIJE ZA CRVENU STRANU*******************************************************************************
															Kordinate na koje ce robot ici ako je na crvenoj strani i smer kretanja.
*************************************************************************************************************************************************************************************/

#define brojPozicijaCrvenaStrana 1

const unsigned int pozicijaCrvenoX[brojPozicijaCrvenaStrana] PROGMEM= // X osa
{
	2000
};

const unsigned int pozicijaCrvenoY[brojPozicijaCrvenaStrana]PROGMEM= //Y osa
{
	1000
};

const signed char orijentacijaRobotaCrveno[brojPozicijaCrvenaStrana]PROGMEM=
{
	1
};

/********************************************************************************CRVENA STRANA****************************************************************************************
*************************************************************************************************************************************************************************************/
void crvenaStrana()
{
	
	eNesto state = FAST_AND_FURIOUS;
	unsigned char pozicija = 0, novaPozicija = 0;
	
	setPosition(1000,1000,0);
	
	while (1)
	{
		switch (state)
		{	
			case FAST_AND_FURIOUS:
			
			for ( pozicija = novaPozicija; pozicija < brojPozicijaCrvenaStrana; pozicija++ )
			{
				if( gotoXY(pgm_read_word(&pozicijaCrvenoX[pozicija]),pgm_read_word(&pozicijaCrvenoY[pozicija]),NORMALNO,pgm_read_byte(&orijentacijaRobotaCrveno[pozicija]),STANDARD) ==  DETEKTOVAN )
				{
					novaPozicija = pozicija;
					state = COLLISION;
					
					break;
				}//end gotoXY if
			}//end for
			
			case COLLISION:
			
			if (novaPozicija == 0)
			{
				_delay_ms(500);
				state = FAST_AND_FURIOUS;
				_delay_ms(1000);
				
				break;
			}//end pozicija
		}//end switch
	}//end while 1
}//end crvena strana





