/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   28/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
    void (*ptf)(void);
    u8 periodicity;
    u8 state;
    u8 First_delay;
    
}task_t;


#define NULL ((void *)0)



#endif