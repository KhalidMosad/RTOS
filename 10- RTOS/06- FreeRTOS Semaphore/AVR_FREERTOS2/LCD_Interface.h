/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 9/4/2021                                                                                      */
/*******************************************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_VidInit(void);
void LCD_VidSendData(u8 copy_u8data);
void LCD_VidSendCommand(u8 copy_u8command);
void LCD_VidSendString(u8 *copy_u8string);
void LCD_VidSendNumber( u8 copy_u16number);
void LCD_VidSetPosition(u8 raw, u8 column);
void LCD_VidClear(void);
void LCD_VidShiftRight(void);
void LCD_VidShiftLeft(void);
void LCD_voidReturnHome(void);




#endif
/* LCD_INTERFACE_H_ */
