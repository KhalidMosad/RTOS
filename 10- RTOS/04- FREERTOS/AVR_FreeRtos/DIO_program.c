/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   29/11/2020          */
/*********Version: 1                     */
/****************Desc: *******************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_register.h"
#include"DIO_config.h"
#include"DIO_interface.h"

void DIO_VidSetPinDirection		(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8state)
{
	if(OUTPUT==copy_U8state)
	{
		switch (copy_u8port)
		{
			case PORTA:SET_BIT(DDRA, copy_U8pin); break;
			case PORTB:SET_BIT(DDRB, copy_U8pin); break;
			case PORTC:SET_BIT(DDRC, copy_U8pin); break;
			case PORTD:SET_BIT(DDRD, copy_U8pin); break;
	
		}	
	}
	else if(INPUT==copy_U8state)
	{
		switch(copy_u8port)
		{
			case PORTA:CLR_BIT(DDRA, copy_U8pin); break;
			case PORTB:CLR_BIT(DDRB, copy_U8pin); break;
		    case PORTC:CLR_BIT(DDRC, copy_U8pin); break;
		    case PORTD:CLR_BIT(DDRD, copy_U8pin); break;
		}	
	}
	else
	{
		
	}
	
}
void DIO_VidSetPinValue			(u8 copy_u8port, u8 copy_U8pin, u8 copy_U8value)
{
	if(HIGH==copy_U8value)
	{
		switch (copy_u8port)
		{
			case PORTA:SET_BIT(PORT_A, copy_U8pin); break;
			case PORTB:SET_BIT(PORT_B, copy_U8pin); break;
			case PORTC:SET_BIT(PORT_C, copy_U8pin); break;
			case PORTD:SET_BIT(PORT_D, copy_U8pin); break;
	
		}	
	}
	else if(LOW==copy_U8value)
	{
		switch(copy_u8port)
		{
			case PORTA:CLR_BIT(PORT_A, copy_U8pin); break;
			case PORTB:CLR_BIT(PORT_B, copy_U8pin); break;
		    case PORTC:CLR_BIT(PORT_C, copy_U8pin); break;
		    case PORTD:CLR_BIT(PORT_D, copy_U8pin); break;
		}	
	}
	else
	{
		
	}	
	
	
	
}


u8 DIO_VidGetPinValue			(u8 copy_u8port, u8 Copy_U8Pin)
{
	u8 Lcal_U8PinResult=0;
	switch(copy_u8port){

			case PORTA :		Lcal_U8PinResult=GET_BIT(PINA,Copy_U8Pin);	        break;
			case PORTB :		Lcal_U8PinResult=GET_BIT(PINB,Copy_U8Pin); 		    break;
			case PORTC :		Lcal_U8PinResult=GET_BIT(PINC,Copy_U8Pin);			break;
			case PORTD :		Lcal_U8PinResult=GET_BIT(PIND,Copy_U8Pin);			break;

			}


return(Lcal_U8PinResult);
	
	
}

void DIO_VidSetPortDirection	(u8 copy_u8port, u8 copy_U8state)
{
	
	if(OUTPUT==copy_U8state)
	{
		switch (copy_u8port)
		{
			case PORTA:DDRA= ALL_OUTPUT		; break;
			case PORTB:DDRB= ALL_OUTPUT		; break;
			case PORTC:DDRC= ALL_OUTPUT		; break;
			case PORTD:DDRD= ALL_OUTPUT		; break;
	
		}	
	}
	else if(INPUT==copy_U8state)
	{
		switch(copy_u8port)
		{
			case PORTA:DDRA= ALL_INPUT		; break;
			case PORTB:DDRB= ALL_INPUT		; break;
			case PORTC:DDRC= ALL_INPUT		; break;
			case PORTD:DDRD= ALL_INPUT		; break;
		}	
	}
	else
	{
		
	}
	
	
}
void DIO_VidSetPortValue		(u8 copy_u8port, u8 copy_U8value)
{
		
		switch (copy_u8port)
		{
			case PORTA:PORT_A=copy_U8value		; break;
			case PORTB:PORT_B=copy_U8value		; break;
			case PORTC:PORT_C=copy_U8value		; break;
			case PORTD:PORT_D=copy_U8value		; break;
	
		}	
	
	
	
	
}

void DIO_VidTogglePin			(u8 copy_u8port, u8 copy_U8pin)
{

		switch (copy_u8port)
		{
					case PORTA:TOG_BIT(PORT_A, copy_U8pin); break;
					case PORTB:TOG_BIT(PORT_B, copy_U8pin); break;
					case PORTC:TOG_BIT(PORT_C, copy_U8pin); break;
					case PORTD:TOG_BIT(PORT_D, copy_U8pin); break;
		}

}

u8 DIO_u8GetPortValue(u8 copy_u8port)
{
		u8 Lcal_U8PortResult=0;
	switch(copy_u8port){

			case PORTA :	Lcal_U8PortResult=PINA;	        break;
			case PORTB :	Lcal_U8PortResult=PINB; 		    break;
			case PORTC :	Lcal_U8PortResult=PINC;			break;
			case PORTD :	Lcal_U8PortResult=PIND;			break;

			}


return(Lcal_U8PortResult);
	
	
}



