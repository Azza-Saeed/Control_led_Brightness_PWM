/*
 * App_Program.c
 *
 * Created: 9/6/2023 8:52:54 PM
 *  Author: Azza Saeed
 */ 


#include "App_Private.h"
#include "TIMER0_Private.h"
#include "BLUE_LED_Private.h"


State_Error APP_Init(void){
	State_Error Local_Error=State_SUCCESS;
	DIO_SetPin_Direction(DIO_PORTA,4,1);
	BLUE_LED_Initializ();
	timer0_overflow_init_interrupt();
	timer_CTC_init_interrupt();
	timer_wave_fastPWM();
	//Set_Global_INT(ON);
    return Local_Error;
}
State_Error APP_main(void){
	State_Error Local_Error=State_SUCCESS;
	Main_Task();
	return Local_Error;

}

State_Error Main_Task(void){
	State_Error Local_Error=State_SUCCESS;
	UINT8_t counter1=0;
	UINT8_t counter=0;
	
	for(counter=100;counter>=0;counter--)
	{
		Set_Duty(counter);
		_delay_ms(10);
	}
	for(counter1=0;counter1<=100;counter1++)
	{
		Set_Duty(counter1);
		_delay_ms(10);
	}
	return Local_Error;
}

State_Error Set_Duty(unsigned char duty_Cycle)
{
	State_Error Local_Error=State_SUCCESS;
	OCR0=(duty_Cycle * Total_Time) / DIVISION_FAC;
    return Local_Error;
}


ISR(TIMER0_OVF_vect)
{
	BLUE_LED_TGL();
}
ISR(TIMER0_COMP_vect)
{
	BLUE_LED_TGL();
}