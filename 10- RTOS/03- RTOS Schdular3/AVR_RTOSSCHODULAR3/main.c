/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   28/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"TIMER_interface.h"
#include"RTOS_interface.h"

void Led1(void)
{
	DIO_VidTogglePin(PORTA,PIN0);
}
void Led2(void)
{
	DIO_VidTogglePin(PORTA,PIN1);

}
void Led3(void)
{
	DIO_VidTogglePin(PORTA,PIN2);

}
void Led4(void)
{
	DIO_VidTogglePin(PORTA,PIN3);

}



void main()
{
    DIO_VidSetPortDirection(PORTA,OUTPUT);
    RTOS_VoidStart();
	RTOS_VoidCreateTask(5	,	&Led1	,0, 	RESUMED , 7);
	RTOS_VoidCreateTask(1	,	&Led2	,1, 	RESUMED	, 0);
	RTOS_VoidCreateTask(10	,	&Led3	,2, 	RESUMED , 2);
	RTOS_VoidCreateTask(5	,	&Led4	,3, 	RESUMED , 2);


while(1);
}

