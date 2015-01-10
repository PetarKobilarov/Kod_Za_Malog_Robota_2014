#ifndef ODOMETRY_H_
#define ODOMETRY_H_

//*******************************************************************************MOGUCNOSTI KRETNJI***********************************************************************************
#define KRETNJE_ZAVRSENO		0
#define NEDEFINISANO			1
#define DETEKTOVAN_PROTIVNIK	2
#define ZAGLAVLJEN				3
//************************************************************************************************************************************************************************************

//***********************************************************************************BRZINE*******************************************************************************************    
#define SPOR0		40
#define NORMALNO	120
#define BRZO		160
//************************************************************************************************************************************************************************************

void setSpeed( unsigned char brzina );
void setPosition ( unsigned int X, unsigned int Y, signed int smer );
unsigned int rotate( signed int ugao, unsigned char brzina );
unsigned int setUgao( signed int apsolutniUgao, unsigned char brzina );
unsigned int moveOnDirection( signed int razdaljina, unsigned char brzina, int tipKretanja );
char gotoXY( unsigned int X, unsigned int Y, unsigned char brzina, signed char smer, int tipKretanja );
void stop(void);
char getY(void);
char getX(void);

#endif /* ODOMETRY_H_ */