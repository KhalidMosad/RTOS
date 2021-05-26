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


void Led1(void* ptr)
{
	while(1)
	{

	DIO_VidTogglePin(0,PIN0);
	vTaskDelay(4000);
	}
}
void Led2(void* ptr)
{
	while(1)
	{
	DIO_VidTogglePin(0,PIN1);
	vTaskDelay(3000);
	}

}
void Led3(void* ptr)
{
	while(1)
	{
	DIO_VidTogglePin(0,PIN2);
	vTaskDelay(2000);
	}
}
void Led4(void* ptr)
{
	while(1)
	{
	DIO_VidTogglePin(0,PIN3);
	vTaskDelay(1000);
	}
}




int main()
{
	xTaskHandle * LED1Handle;
	xTaskHandle * LED2Handle;
	xTaskHandle * LED3Handle;
	xTaskHandle * LED4Handle;

	DIO_VidSetPortDirection(0,OUTPUT);
	DIO_VidSetPortValue(0,LOW);

		if(xTaskCreate(Led1,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL)==pdPASS)
		{
				DIO_VidSetPinValue(0,PIN6,HIGH);
		}
		xTaskCreate(Led2,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);
		xTaskCreate(Led3,NULL,configMINIMAL_STACK_SIZE,NULL,3,NULL);
		xTaskCreate(Led4,NULL,configMINIMAL_STACK_SIZE,NULL,4,NULL);
//	xTaskCreate(Led1,NULL,300,NULL,3,NULL);
		// 300 Means 300 words  32 * 300 bits .... 600 bytes
//	xTaskCreate(Led2,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);
//	xTaskCreate(Led3,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
//	xTaskCreate(Led4,NULL,configMINIMAL_STACK_SIZE,NULL,0,NULL);
//	xTaskCreate(Led1,NULL,200,NULL,1,NULL);
//	xTaskCreate(Led2,NULL,200,NULL,2,NULL);
//	xTaskCreate(Led3,NULL,200,NULL,3,NULL);

	vTaskStartScheduler();


}

