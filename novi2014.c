#define F_CPU 10000000UL
#define F_CPU 10000000UL

#include <avr/io.h>
#include "can.h"
#include <util/delay.h>
#include "odometry.h"
#include "usart.h"
#include "timers.h"
#include "system.h"
#include "detekcijaProtivnika.h"
#include "crvena-ZutaStrana.h"

int main(void)
{	
	_delay_ms(100);
	setRobot();
	_delay_ms(1500);
	
	crvenaStrana();
	
	while(1);
}


