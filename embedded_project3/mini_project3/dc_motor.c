/*
 * dc_motor.c
 *
 *  Created on: May 9, 2023
 *      Author: ahmed
 */
#include"dc_motor.h"
#include"gpio.h"
#include"PWM.h"


void DcMotor_init(void){
/************************************ SETUP MOTOR PINS DIRECTION **************************************/
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
/******************************************************************************************************/

/*************************************** INITIALIZING MOTOR SPEED TO BE ZERO **************************/
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

}

void DcMotor_rotate(DcMotor_State status,uint8 speed_percentage){
if (status == A_CW) {
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
}
else if (status == CW){
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}
else if (status == stop){
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

Timer0_PWM_Init(speed_percentage);
}
