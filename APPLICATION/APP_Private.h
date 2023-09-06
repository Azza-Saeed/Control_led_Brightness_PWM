/*
 * App_Interface.h
 *
 * Created: 9/6/2023 8:53:39 PM
 *  Author: Azza Saeed
 */ 


#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_


#define Total_Time 256 // over flow ticks at any 8 bit register
#define DIVISION_FAC 100
typedef enum{
	State_FAIL=0,
	State_SUCCESS=1
}State_Error;


State_Error APP_Init(void);
State_Error APP_main(void);
State_Error Main_Task(void);
State_Error Set_Duty(unsigned char duty_Cycle);

#endif /* APP_INTERFACE_H_ */