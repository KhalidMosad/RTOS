/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 9/4/2021                                                                                      */
/*******************************************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_configure.h"
#include "LCD_private.h"
#include<avr/delay.h>




void LCD_VidInit(void)
{

	#if LCD_Mode==EIGHT_BIT
	DIO_VidSetPinDirection	( Lcopy_u8PORT	,RS_copy_u8Pin,  OUTPUT);
	DIO_VidSetPinDirection	( Lcopy_u8PORT	,R_w_copy_u8Pin, OUTPUT);
	DIO_VidSetPinDirection	( Lcopy_u8PORT	,E_copy_u8Pin,   OUTPUT);
	_delay_ms(40);
	DIO_VidSetPortDirection	( LDcopy_u8PORT,OUTPUT);

	LCD_VidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_VidSendCommand(0b00001111);
	_delay_ms(1);
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
	LCD_VidSendCommand(0b00000110);
	_delay_ms(1);


	#elif LCD_Mode==FOUR_BIT
	_delay_ms(40);
	DIO_VidSetPinDirection	( Lcopy_u8PORT,RS_copy_u8Pin, OUTPUT);
	DIO_VidSetPinDirection	( Lcopy_u8PORT,R_w_copy_u8Pin,OUTPUT);
	DIO_VidSetPinDirection	( Lcopy_u8PORT,E_copy_u8Pin,  OUTPUT);
	_delay_ms(1);
	DIO_VidSetPortDirection	( LDcopy_u8PORT,OUTPUT);
	LCD_VidSendCommand(0x33);
	_delay_ms(2);
	LCD_VidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	_delay_ms(2);
	LCD_VidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	_delay_ms(2);
	LCD_VidSendCommand(0x0c);	/* Display on cursor off */
	_delay_ms(2);
	LCD_VidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	_delay_ms(2);
	LCD_VidSendCommand(0x01);	/* Clear display screen */
	_delay_ms(2);

	#endif
}

void LCD_VidSendData(u8 copy_u8data)
{
	#if LCD_Mode==EIGHT_BIT
		DIO_VidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,1);
		DIO_VidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
		_delay_ms(1);
		DIO_VidSetPortValue(LDcopy_u8PORT,copy_u8data);
		_delay_ms(1);
		DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		_delay_ms(1);
		DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
        _delay_ms(1);
		
	#elif LCD_Mode==FOUR_BIT
		DIO_VidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT & 0x0F)|(copy_u8data & 0xF0));
		DIO_VidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,1);
		DIO_VidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
		DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		_delay_ms(2);
		DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command

		_delay_ms(2);

		DIO_VidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8data<<4));
		DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		_delay_ms(2);
		DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
		_delay_ms(2);

	#endif
}

void LCD_VidSendCommand(u8 copy_u8command)
{
	#if LCD_Mode==EIGHT_BIT
	DIO_VidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,0);
	DIO_VidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
	
	
	DIO_VidSetPortValue(LDcopy_u8PORT,copy_u8command);
	DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
	_delay_ms(1);
	DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	if (copy_u8command==1)
	_delay_ms(2);
	
	
	
	#elif LCD_Mode==FOUR_BIT
	DIO_VidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8command&0xF0));
	DIO_VidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,0);
	DIO_VidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
	DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);
	_delay_ms(2);
	DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);
	_delay_ms(2);
	DIO_VidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8command<<4)); /* Sending lower cmnds */
	DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);
	_delay_ms(2);
	DIO_VidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);
	_delay_ms(2);

	_delay_ms(5);
	#endif
}

void LCD_VidSendString( u8 *copy_u8string)
{

	u8 i=0;

	while(copy_u8string[i] != '\0')
	{

		LCD_VidSendData(copy_u8string[i]);
		i++;
	}


}

 void LCD_VidSendNumber( u8 copy_u16number)
{

	if (copy_u16number==0)
	{
		LCD_VidSendData('0');
	}
	s8 i=0;
	u8 str_num[5];
	while(copy_u16number>0)
	{
		str_num[i]=copy_u16number%10;
		copy_u16number/=10;
		i++;
	}
	i--;
	while(i>=0)
	{
		switch(str_num[i])
		{
		case 0 : LCD_VidSendData('0');break;
		case 1 : LCD_VidSendData('1');break;
		case 2 : LCD_VidSendData('2');break;
		case 3 : LCD_VidSendData('3');break;
		case 4 : LCD_VidSendData('4');break;
		case 5 : LCD_VidSendData('5');break;
		case 6 : LCD_VidSendData('6');break;
		case 7 : LCD_VidSendData('7');break;
		case 8 : LCD_VidSendData('8');break;
		case 9 : LCD_VidSendData('9');break;
		}

		i--;
	}


}


void LCD_VidSetPosition(u8 raw, u8 column)
{
	if(0==raw)       // raw= 0
	{
	LCD_VidSendCommand(128+column);    // 0b10000000=128 +column
	}
	if(1==raw)
	{
	LCD_VidSendCommand(128+64+column);  //  // 0b10000000=128 +column+64
	                                    // 64 is the start address of row 2
	}

}

void LCD_VidClear(void)
{
	LCD_VidSendCommand(1);


}

void LCD_VidShiftRight(void)
{
	LCD_VidSendCommand(0b00011100);

}

void LCD_VidShiftLeft(void)
{
	LCD_VidSendCommand(0x18);

}

void LCD_voidReturnHome(void)
{
	LCD_VidSendCommand(0x02);

}






