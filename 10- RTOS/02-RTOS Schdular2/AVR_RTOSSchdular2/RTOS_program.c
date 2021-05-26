/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   28/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"TIMER_interface.h"
#include"RTOS_interface.h"
#include"RTOS_private.h"
#include"RTOS_config.h"

task_t SysTask[MAXTASKS] ={0};

void RTOS_VoidStart(void)
{
	TIMER1_Set_callback(&RTOS_VoidSchaduler);
	TM_voidTimerInit();

}


void RTOS_VoidCreateTask(u8 Copy_u8Periodicity, void(*pf)(void),u8 Copy_u8Priority, u8 Copy_u8State)
{
    SysTask[Copy_u8Priority].periodicity = Copy_u8Periodicity;
    SysTask[Copy_u8Priority].ptf  = pf;
    SysTask[Copy_u8Priority].state  = Copy_u8State;
}

void RTOS_VoidSuspendTask(u8 Copy_u8Priority)
{
    SysTask[Copy_u8Priority].state  = SUSPEND;
}

void RTOS_VoidResumeTask(u8 Copy_u8Priority)
{
    SysTask[Copy_u8Priority].state  = RESUMED;
}

void RTOS_VoidKillTask(u8 Copy_u8Priority)
{
    if(SysTask[Copy_u8Priority].state == KILL) 
        SysTask[Copy_u8Priority].ptf  = NULL;
}

void RTOS_VoidSchaduler(void)
{
    static u16 TIMER_TICS = 0;
    TIMER_TICS++;
    for(u8 i=0; i< MAXTASKS; i++)
    {
        if (SysTask[i].ptf)
        {
            if (TIMER_TICS%SysTask[i].periodicity   == 0 && SysTask[i].state == RESUMED )
            {
                SysTask[i].ptf(); 
            }
            else
            {
                
            }            
        }
        else
        {

        }



    }    


}
