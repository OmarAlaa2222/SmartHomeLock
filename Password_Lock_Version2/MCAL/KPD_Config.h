/*
 * KPD_Config.h
 *
 *  Created on: May 24, 2023
 *      Author: Lenovo
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_Port              DIO_u8_PORTB
#define KPD_COLUMN0_PIN       DIO_u8_PIN0
#define KPD_COLUMN1_PIN       DIO_u8_PIN1
#define KPD_COLUMN2_PIN       DIO_u8_PIN2
#define KPD_COLUMN3_PIN       DIO_u8_PIN3

#define KPD_ROW0_PIN       DIO_u8_PIN4
#define KPD_ROW1_PIN       DIO_u8_PIN5
#define KPD_ROW2_PIN       DIO_u8_PIN6
#define KPD_ROW3_PIN       DIO_u8_PIN7


#define KPD_No_Key_Pressed  0xff


#define KPD_Arr_Value         {{'1','2','3','+'},   \
				  	           {'4','5','6','-'},   \
				  	           {'7','8','9','*'},   \
				  	           {'0','=','/','D'}}



#endif /* KPD_CONFIG_H_ */
