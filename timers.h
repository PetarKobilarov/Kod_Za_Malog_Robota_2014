#ifndef _TIMERS_H_INCLUDED
#define _TIMERS_H_INCLUDED

#include <avr/interrupt.h>

#define activateInterrupts()	sei()	
#define disableInterrupts()		cli()

void timer1Init(void);
void timer3Init(void);

extern void debaunsingZaTaster( void );
extern char protocniDelay( unsigned long );
extern void countTime( void );
extern void countCANTime( void );

#endif