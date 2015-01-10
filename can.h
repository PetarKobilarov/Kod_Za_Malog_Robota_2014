/**********************************************************************************
* File Name			: can.h
* Description       : Fajl je .h fajl i sadrzi deklaraciju funkcija za manipulaciju 
                      CAN magistrale. 
					  Magistrala radi na 250kbps, a podrazumeva se 
					  da AT90CAN128 radi na 10Mhz.
					  Magistrala je podesena tako da uvek prima i salje 8 bajtova
**********************************************************************************/

#ifndef CAN_H_
#define CAN_H_


#define XBEE_TX_IDENTIFICATOR			0xA1 // 10
#define KINEZ_TX_IDENTIFICATOR			0XB2 //15
#define DRIVER_TX_IDENTIFICATOR			0xC3
#define DRIVER_LIFT_TX_IDENTIFICATOR	0xD4

#define DRIVER_RX_IDENTIFICATOR 		0x01 //8
#define XBEE_RX_IDENTIFICATOR			0x02 //11
#define KINEZ_RX_IDENTIFICATOR			0x03 //20
#define DRIVER_LIFT_RX_IDENTIFICATOR	0x04

/*********************************************************************************
* Function Name		: CAN_checkRx
* Description       : Funkcija vraca broj neiscitanih podataka iz bafera buffer
* Parameters        : unsigned char buffer
* Return Value      : unsigned char
*********************************************************************************/
unsigned char CAN_CheckRX(unsigned char nodeID);


/*********************************************************************************
* Function Name		: CAN_read
* Description       : Funkcija cita 8- bajtni niz karaktera iz prijemnog bafera CAN 
					  magistrale.
				      U slucaju da nema primljenih podataka funkcija ceka na 
					  na podatak.
* Parameters        : canMsg *rxData
* Return Value      : void
*********************************************************************************/
char CAN_Read(unsigned char *buffer, unsigned char sendingNodeID, long timeout);


/*********************************************************************************
* Function Name		: CAN_write
* Description       : Funkcija upisuje 8 bajtova podataka u predajni bafer CAN
					  magistrale. Pored tih podataka, salje se i njen 
					  identifikator messIdentificator.
* Parameters        : canMgs txData
* Return Value      : char
*********************************************************************************/
char CAN_Write(unsigned char *data, unsigned char receiveingNodeAddress);

void CAN_Init(unsigned char numOfNodes);


#endif /* CAN_H_ */