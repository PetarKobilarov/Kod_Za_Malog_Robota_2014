#ifndef SYSTEM_H_
#define SYSTEM_H_

#define MATCHTIME 90000UL

typedef struct{
	volatile unsigned long systemTime;
	volatile char matchStarted;
	volatile char theEnd;
}tSys;

void setRobot( void );
void startMatch( void );

#endif /* SYSTEM_H_ */