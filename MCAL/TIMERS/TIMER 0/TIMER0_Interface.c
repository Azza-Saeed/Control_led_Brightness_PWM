/*
 *  TINER0_Interface.c
 *
 *  Created: 27/8/2023 11 AM
 *  Author: Azza Saeed
 */

#include "TIMER0_Private.h"

 /*
 * Description: function to initialize the Timer0
 * input: nothing
 * return: Error State
 */
void timer0_init(){
/*NORMAL OVF*/
TCCR0 = 0x85;
/*OVF interrupt*/
TIMSK = 0X01;
///*TO GENERATE */
TCNT0 = 0;
Set_Global_INT(ON);
}
 /*
 * Description: function to deinitialize timer0
 * input: nothing
 * return: Error State
 */
void timer0_deinit(){
	
	TCCR0=0;
	Set_Global_INT(OFF);
	}


void timer0_overflow_init_interrupt(void)
{
	/* select Over mode*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*load a value in TCNT0 */
	TCNT0=0;
	/* select timer clock prescaller 256  */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	/* enable interrupt*/
	Set_Global_INT(ON);

}

void timer_CTC_init_interrupt(void)
{
	SET_BIT(DDRB,3);// output pin
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=128;
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	/* select timer clock  256 prescaler */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	/* enable interrupt*/
	Set_Global_INT(ON);
	SET_BIT(TIMSK,OCIE0);
}

void timer_wave_fastPWM(void)
{
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* select timer clock 64 prescaller   */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode) */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	OCR0=0;
}