#include "can.h"
#include "detekcijaProtivnika.h"
#include <avr/io.h>
#include <util/delay.h>					

static volatile unsigned char i = 0;
static volatile unsigned char j = 0;								
static volatile unsigned char SENZOR_matrica[10][3];											

void debaunsingZaTaster( void )
{
	for ( j = 0; j < 10; j++ )
	{
		for ( i = 0; i < 3; i++ )
		{
			switch ( j )
				{
					case 1 :
						SENZOR_matrica[j][i] = TASTER_ROBOT_NAPRED_LEVO; 
							break;
					case 2 :
						SENZOR_matrica[j][i] = TASTER_ROBOT_NAPRED_DESNO;
							break;
					case 3 :
						SENZOR_matrica[j][i] = SENZOR_ROBOT_NAPRED_LEVO;
							break;
					case 4 :
						SENZOR_matrica[j][i] = SENZOR_ROBOT_NAPRED_DESNO;
							break;
					case 5 :
						SENZOR_matrica[j][i] = TASTER_ROBOT_NAZAD;
							break;
					case 6 :
						SENZOR_matrica[j][i] = SENZOR_ROBOT_NAZAD_LEVO;
							break;
					case 7 :
						SENZOR_matrica[j][i] = SENZOR_ROBOT_NAZAD_DESNO;
							break;
					case 8 :
						SENZOR_matrica[j][i] = JUMPER;
							break;
					case 9 :
						SENZOR_matrica[j][i] = PREKIDAC_BOJA;
							break;
					case 10 :
						SENZOR_matrica[j][i] = PREKIDAC_TAKTIKA;
							break;
				}
		}
	}
	
}

int senzorikaNapredProvera( void )
{
	for ( j = 0; j < 4; j++ )
	{
		if ( SENZOR_matrica[j][0] | SENZOR_matrica[j][1] | SENZOR_matrica[j][2] )
			return 0;
	}
			return 1;
}

int senzorikaNazadProvera( void )
{
	for ( j = 4; j < 7; j++ )
	{
		if ( SENZOR_matrica[j][0] | SENZOR_matrica[j][1] | SENZOR_matrica[j][2] )
			return 0;
	}
			return 1;
}

int dobiDetekciju( int smer )
{
	if ( smer == NAPRED )
	{	
		if ( senzorikaNapredProvera() == 1 )
			return 1;
	}
	else if ( smer == NAZAD )
	{
		if ( senzorikaNazadProvera() == 1 )
			return 1;
	}
}