/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 9/4/2021                                                                                     */
/*******************************************************************************************************/
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define EIGHT_BIT		0
#define FOUR_BIT		1

#define CLEAR_DISPLAY				0x01
#define RETURN_HOME					0x02
#define SHIFT_CURSOR_LEFT			0x04
#define SHIFT_CURSOR_RIGHT			0x06
#define SHIFT_DISPLAY_RIGHT			0x05
#define SHIFT_DISPLAY_LEFT			0x07
#define DISPLAY_CURSOR_OFF			0x08
#define DISPLAY_OFF_CURSOR_ON		0x0A
#define DISPLAY_ON_CURSOR_OFF		0x0C
#define DISPLAY_ON_CURSOR_BLINK		0x0F
#define SHIFT_ENTIRE_DISPLAY_LEFT	0x18
#define SHIFT_ENTIRE_DISPLAY_RIGHT	0x1C
#define FORCE_CURSOR_FIRST_LINE		0x80
#define FORCE_CURSOR_SECOND_LINE	0xC0
#define TWO_LINES_FOUR_BIT			0x28
#define TWO_LINES_EIGHT_BIT			0x28

#endif
