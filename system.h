#ifndef SYSTEM_H_
#define SYSTEM_H_

#define MATCHTIME 90000UL

typedef struct{
	volatile unsigned long systemTime;
	volatile char matchStarted;
	volatile char theEnd;
	volatile char pisaj;
}tSys;

char setServo( signed int position, unsigned char channel );
char setAx( unsigned int position, unsigned int speed,unsigned char id );
void setRobot( void );
void startMatch( void );
void countTime( void );

#endif /* SYSTEM_H_ */