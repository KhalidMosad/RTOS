/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   20/1/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef  DIO_interface_h_
#define  DIO_interface_h_

#define		PORTA	0
#define		PORTB	1
#define		PORTC	2
#define		PORTD	3



#define 	PIN0	0
#define 	PIN1	1
#define 	PIN2	2
#define 	PIN3	3
#define 	PIN4	4
#define 	PIN5	5
#define 	PIN6	7
#define 	PIN7	7


#define		INPUT	0
#define		OUTPUT	1

#define		HIGH	1
#define		LOW		0

#define		ALL_INPUT	0x00
#define		ALL_OUTPUT	0xff


void DIO_VidSetPinDirection		(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8state);
void DIO_VidSetPinValue			(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8value);
u8 DIO_VidGetPinValue			(u8 copy_u8port, u8 Copy_U8Pin);
void DIO_VidSetPortDirection	(u8 copy_u8port, u8 copy_U8state);
void DIO_VidSetPortValue		(u8 copy_u8port, u8 copy_U8value);
void DIO_VidTogglePin			(u8 copy_u8port, u8 copy_U8pin);
u8 DIO_u8GetPortValue			(u8 copy_u8port);

#endif
