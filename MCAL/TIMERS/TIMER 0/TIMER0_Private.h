/*
 *  TINER0_Private.h
 *
 *  Created: 27/8/2023 11 AM
 *  Author: Azza Saeed
 */


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
 
#include "CPU_Configuration.h"

void timer0_init(void);

void timer0_deinit(void);

void timer0_overflow_init_interrupt(void);
void timer_CTC_init_interrupt(void);
void timer_wave_fastPWM(void);


#endif /* TIMER0_PRIVATE_H_ */