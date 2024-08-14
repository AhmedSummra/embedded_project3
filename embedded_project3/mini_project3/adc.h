 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/**************************select interrupt or polling***************************/
#define POLLING_MODE
/************************************** select the internal reference type*******/
#define INTERNAL_REF
#ifdef  INTERNAL_REF
#define ADC_INTERNAL_REF_VALUE   2.56
#endif
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE      2.56
/********************************structures definitions*************************/
 typedef struct{
	uint8 ADC_RefrenceVoltage;
	uint8 ADC_Prescaler;
}ADC_configType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(ADC_configType *ADC_configPtr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
