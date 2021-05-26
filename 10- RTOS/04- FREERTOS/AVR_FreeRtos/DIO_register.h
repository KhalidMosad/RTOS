/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef _DIO_REGISTER_
#define _DIO_REGISTER_

#define DDRA *((u8*)0x3A)
#define DDRC *((u8*)0x34)
#define DDRB *((u8*)0x37)
#define DDRD *((u8*)0x31)

#define PORT_A *((u8*)0x3B)
#define PORT_B *((u8*)0x38)
#define PORT_C *((u8*)0x35)
#define PORT_D *((u8*)0x32)

#define PINA *((volatile u8*)0x39)
#define PINB *((volatile u8*)0x36)
#define PINC *((volatile u8*)0x33)
#define PIND *((volatile u8*)0x30)

#endif


	
	
	
	
	
	
	
  	

