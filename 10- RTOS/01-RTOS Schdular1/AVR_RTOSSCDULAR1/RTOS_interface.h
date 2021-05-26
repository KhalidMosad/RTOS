/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   28/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H


void RTOS_VoidStart(void);
void RTOS_VoidCreateTask(u8 Copy_u8Periodicity, void(*pf)(void), u8 Copy_u8Priority);
void RTOS_VoidSchaduler(void);



#endif