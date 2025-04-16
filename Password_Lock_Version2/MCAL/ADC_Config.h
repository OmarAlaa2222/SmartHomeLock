/*
 * ADC_Config.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Lenovo
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*  Voltage Reference Selection :
 *
 * 1-AREF
 * 2-AVCC (External Capcitaor)
 * 3-Internal 2.56 V Voltage Reference
 *
 */
#define Voltage_Reference  AVCC

/*  ADC PRESCALAR
 *  From 2 , 4 , 8 , 16 , 32 , 64 , 128
 */

#define ADC_PreScalar 128


#define ADC_ADJUST RIGHT








#endif /* ADC_CONFIG_H_ */
