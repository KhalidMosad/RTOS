/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   28/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H


void RTOS_VoidStart(void);
void RTOS_VoidCreateTask(u8 Copy_u8Periodicity, void(*pf)(void),u8 Copy_u8Priority, u8 Copy_u8State);
void RTOS_VoidSchaduler(void);
void RTOS_VoidSuspendTask(u8 Copy_u8Priority);
void RTOS_VoidResumeTask(u8 Copy_u8Priority);
void RTOS_VoidKillTask(u8 Copy_u8Priority);


#define RESUMED  1
#define SUSPEND  0
#define KILL ((void *)0)


#endif
