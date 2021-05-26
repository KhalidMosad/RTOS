/*********Author : Khalid Mosaad Zakaria */

/*********Date   :   16/4/2021          */
/*********Version: 1                     */
/****************Desc: *******************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Timer_interface.h"
#include"Timer_private.h"
#include"Timer_config.h"
#include"DIO_interface.h"
/*Input Capture Variables*/ 
u16 ov=0;
u8 flag=0;
u16 snap1;
u32 snap2;
u32 snap3;



void(*callback)(void)=NULL;

void TIMER1_Set_callback(void(*ptr)(void))
{
	callback=ptr;

}
void TM_voidTimerInit(void)
{
    #if TIMER_S== TIMER0

        #if TIMER0_M==NORMAL
            CLR_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            SET_BIT(TIMSK, TOIE0);

        #elif TIMER0_M==CTC
            CLR_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            OCR0= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE0);

        // WAVE GENERATOR ON PINB.3
            CLR_BIT(TCCR0,COM01);
            SET_BIT(TCCR0,COM00);



        #elif TIMER0_M==PWM
            SET_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            #if PWM_M == NON_INVERTED
                SET_BIT(TCCR0, COM01);
                CLR_BIT(TCCR0, COM00);
            #elif PWM_M==INVERTED
                SET_BIT(TCCR0, COM01);
                SET_BIT(TCCR0, COM00);
            #endif
        #elif TIMER0_M==FAST_PWM
            SET_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            #if PWM_M == NON_INVERTED
                SET_BIT(TCCR0, COM01);
                CLR_BIT(TCCR0, COM00);
            #elif PWM_M==INVERTED
                SET_BIT(TCCR0, COM01);
                SET_BIT(TCCR0, COM00);
            #endif

        #endif

        #if TIMER0_CLK == NO_CLOCK
            CLR_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK
            SET_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_8
            CLR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_64
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            CLR_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_256
            CLR_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == CLK_1024
            SET_BIT(TCCR0,CS00);
            CLR_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == EXTERNAL_CLK_FALLING
            CLR_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        #elif TIMER0_CLK == EXTERNAL_CLK_RISING
            SET_BIT(TCCR0,CS00);
            SET_BIT(TCCR0,CS01);
            SET_BIT(TCCR0,CS02);
        
        #endif


    #elif TIMER_S== TIMER1
        #if TIMER1_M==T1_NORMAL    
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
            SET_BIT(TIMSK, TOIE1);
        #elif TIMER1_M==PWM_8BIT       
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_9BIT  
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_10BIT   
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==T1_CTC     
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
            OCR1A= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE1A);

            /*WE CAN USE OCR1B In Here */
        #elif TIMER1_M==FAST_PWM_8BIT  
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_9BIT  
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_10BIT  
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            CLR_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE_FREQ_CORRECT_ICR1  
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE_FREQ_CORRECT_OCR1A 
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE__CORRECT_ICR1      
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==PWM_PHASE__CORRECT_OCR1A     
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            CLR_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==CTC_ICR1       
            CLR_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==RESERVED       
            SET_BIT(TCCR1,WGM10);
            CLR_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_ICR1    
            CLR_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #elif TIMER1_M==FAST_PWM_OCR1A   
            SET_BIT(TCCR1,WGM10);
            SET_BIT(TCCR1,WGM11);
            SET_BIT(TCCR1,WGM12);
            SET_BIT(TCCR1,WGM13);
        #endif
        #if TIMER1_CLK == NO_CLOCK
            CLR_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK
            SET_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_8
            CLR_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_64
            SET_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            CLR_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_256
            CLR_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == CLK_1024
            SET_BIT(TCCR1,CS10);
            CLR_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == EXTERNAL_CLK_FALLING
            CLR_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        #elif TIMER1_CLK == EXTERNAL_CLK_RISING
            SET_BIT(TCCR1,CS10);
            SET_BIT(TCCR1,CS11);
            SET_BIT(TCCR1,CS12);
        
        #endif








    #elif TIMER_S== TIMER2
        #if TIMER2_M==NORMAL
            CLR_BIT(TCCR2,WGM20);
            CLR_BIT(TCCR2,WGM21);
            SET_BIT(TIMSK, TOIE2);

        #elif TIMER2_M==CTC
            CLR_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);
            OCR0= OCR_VALUE_CTCMode;
            SET_BIT(TIMSK, OCIE2);

        // WAVE GENERATOR ON PINB.3
            CLR_BIT(TCCR2,COM21);
            SET_BIT(TCCR2,COM20);



        #elif TIMER2_M==PWM
            SET_BIT(TCCR2,WGM20);
            CLR_BIT(TCCR2,WGM21);

        #elif TIMER2_M==FAST_PWM
            SET_BIT(TCCR2,WGM20);
            SET_BIT(TCCR2,WGM21);

        #endif

        #if TIMER2_CLK == NO_CLOCK
            CLR_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK
            SET_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_8
            CLR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_32
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            CLR_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_64
            CLR_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_128
            SET_BIT(TCCR2,CS20);
            CLR_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_256
            CLR_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);
        #elif TIMER2_CLK == CLK_1024
            SET_BIT(TCCR2,CS20);
            SET_BIT(TCCR2,CS21);
            SET_BIT(TCCR2,CS22);    

        #endif

    #else
    #endif
   
    SET_BIT(SREG, BIT7);
    
}


void TM_VoidPrealoadOverFlow(void)
{ 
    #if TIMER_S== TIMER0
        TCNT0= PRELOAD_VALUE;
    #elif TIMER_S== TIMER1
        TCNT1= PRELOAD_VALUE;      
    #elif TIMER_S== TIMER2
        TCNT2= PRELOAD_VALUE;  
    #endif

    
}


void TM_VoidSetDuty(u16 Copy_U8Duty)
{
    #if TIMER_S== TIMER0
        OCR0= Copy_U8Duty;
    #elif TIMER_S== TIMER1
        OCR1A= Copy_U8Duty;
    #elif TIMER_S== TIMER2
        OCR2 =Copy_U8Duty;
    #endif
}

void TM1_VoidInputCapture(void)
{ 
    DIO_VidSetPinDirection(PORTD,PIN6,INPUT);
    /*IT can be any mode of the Timer except 8,10,12,14*/
    SET_BIT(TIMSK,TICIE1);
    SET_BIT(TCCR1,ICES1);   // Rising Edge

}

void __vector_11(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT0=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN0);
		counter=0;
	}


}

void __vector_10(void)
{
    static u16 Counter=0;
	Counter++;
	if(Counter==5000)
	{

        DIO_VidTogglePin(PORTA,PIN0);
		Counter=0;

	}

}

void __vector_5(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT2=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN0);
		counter=0;
	}

}

/*
void __vector_9(void)
{
    static u16 counter=0;
	counter++;
	if(counter==245)
	{
		TCNT1=PRELOAD_VALUE;
		DIO_VidTogglePin(PORTA,PIN0);
		counter=0;
	}


}*/

void __vector_6(void)
{
	if(0==flag)
	{
		snap1=ICR1;
		ov=0;
		// falling edge
		CLR_BIT(TCCR1,ICES1);
		flag=1;
	}
	else if(1==flag)
	{
		snap2= ICR1+ (ov*65536);
		flag=2;
		// rising edge
		SET_BIT(TCCR1,ICES1);
	}
	else if (2==flag)
	{


		snap3= ICR1+ (ov*65536);

		flag=3;
	}


}

void __vector_9(void)
{
	ov++;
}

void __vector_7(void)
{
	DIO_VidTogglePin(PORTA,PIN4);
	callback();
}
