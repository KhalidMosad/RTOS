/*

 * main.c

 *
 *  Created on: Dec 15, 2020
 *      Author: Khaled
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include<util/delay.h>
#include"FreeRTOS.h"
#include"task.h"
#include "stdio.h"
#include "avr/delay.h"
#include "semphr.h"
#include "LCD_Interface.h"

xSemaphoreHandle LCDsem;


void LCDTASK1(void* ptr)
{
	while(1)
	{
		u8 State = xSemaphoreTake(LCDsem, 5);
		if (State== pdPASS)
		{
			LCD_VidSendString("Khalid Mosad");
			xSemaphoreGive(LCDsem);
		}
		vTaskDelay(1000);
	}
}
void LCDTASK2(void* ptr)
{
	while(1)
	{
		u8 State = xSemaphoreTake(LCDsem, 5);
		if (State== pdPASS)
		{
			LCD_VidSendString("Zakaria Abdullkader");
			xSemaphoreGive(LCDsem);

		}
		vTaskDelay(1000);
	}

}






int main()
{
	vSemaphoreCreateBinary(LCDsem);
	LCD_VidInit();
	DIO_VidSetPortDirection(1,OUTPUT);
		if(xTaskCreate(LCDTASK1,NULL,250,NULL,5,NULL)==pdPASS)
		{
				DIO_VidSetPinValue(1,PIN6,HIGH);
		}
		if(xTaskCreate(LCDTASK2,NULL,250,NULL,5,NULL)==pdPASS)
		{
			DIO_VidSetPinValue(1,PIN7,HIGH);
		}


	vTaskStartScheduler();
while(1);

}

