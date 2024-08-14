/*
 * project3.c
 *
 *  Created on: May 9, 2023
 *      Author: ahmed
 */
#include"adc.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"dc_motor.h"
#include"gpio.h"
#include"util/delay.h"


int main(void){
	/********************************************SETUP CONFIGRATION OF ADC**************************************************/
		ADC_configType *config_ptr;
	/***********************************************************************************************************************/
ADC_init(config_ptr);
DcMotor_init();
LCD_init();

LCD_displayString("WELCOME !");
_delay_ms(1000);
LCD_clearScreen();



	while(1){
uint8 t;

LCD_displayString("FAN STATUS : ");
LCD_moveCursor(1,0);
LCD_displayString("TEMPERATURE =");
LCD_moveCursor(1,13);
t=LM35_getTemperature();


if(t>99){
	LCD_intgerToString(t);
}
else{
	LCD_intgerToString(t);
	LCD_displayCharacter(' ');
}
if(t>=0&&t<30){
	LCD_moveCursor(0,13);
	LCD_displayString("OFF");
	DcMotor_rotate(stop,0);
}
else if(t>=30&&t<60) {
	LCD_moveCursor(0,13);
	LCD_displayString("ON ");
	DcMotor_rotate(CW,64);
}
else  if(t>=60&&t<90){
	LCD_moveCursor(0,13);
	LCD_displayString("ON ");
	DcMotor_rotate(CW,128);
}
else if(t>=90&&t<120){
	LCD_moveCursor(0,13);
	LCD_displayString("ON ");
	DcMotor_rotate(CW,191);
}
else if(t>=120){
	LCD_moveCursor(0,13);
	LCD_displayString("ON ");
	DcMotor_rotate(CW,255);
}

	}
	return 0;
}

