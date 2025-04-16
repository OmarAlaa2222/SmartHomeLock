/*
 * main.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Lenovo
 */
#define F_CPU  8000000UL
#include <util/delay.h>

#include "BIT_MATH.h"

#include "STD_TYPES.h"

#include "Port_Interface.h"
#include "DIO_Interface.h"

#include "KPD_Interface.h"
#include "LCD_Interface.h"


#include "Timer_Interface.h"
#include "ADC_Interface.h"



u16 App_u16ADCDigitalValue =0;

static u8 FLAG=0;
void GetDigital(void){


	App_u16ADCDigitalValue = ADC_u16GetADCRegValue();
}


void main (void){

	u8 Password[3];
	u8 i, Reading,Check,flag=0,Reset,time;
	u16 Local_u16AnalogValue=0;
	u16 Local_u16Temp=0;


	TMRS_voidTMR1Init();
	PORT_voidInit();
	ADC_voidInit();
	TMRS_voidTMR0Init();

	LCD_voidInit();

	GIE_voidEnable();



	LCD_voidGoToPos(0,1);
	LCD_voidSendString("Welcome To");
	LCD_voidGoToPos(1,1);
	LCD_voidSendString("Omar House");
	_delay_ms(3000);
	LCD_voidClearDisplay();

	LCD_voidSendString("Enter Password");
	_delay_ms(1000);
	LCD_voidClearDisplay();

	LCD_voidGoToPos(0,1);
	LCD_voidSendString("Password:");

	TMRS_voidTimer1SetOverflowValue(19999);




	while (1){

		// TMRS_voidTimer1SetCompareMatchValue(500);

		ADC_voidGetDigitalValueAsynch(ADC_u8_ADC_Channel_4,&GetDigital);
		Local_u16AnalogValue=(App_u16ADCDigitalValue*5000UL)/1024;
		Local_u16Temp=Local_u16AnalogValue/10;








			for (i=0;i<3;i++){
				Reading =KPD_u8GetPressedKey();
				if (Reading != 0xff){
				Password[i]=Reading;


				LCD_voidSendData(Password[i]);
				}
				else if (Reading == 0xff){
					i--;
				}
			}

			_delay_ms(2000);


//Password Check



			if ((Password[0]=='1') && (Password[1]=='3') && (Password[2]=='3') ){

				LCD_voidClearDisplay();
				_delay_ms(1000);
				LCD_voidSendString("Password Right");
				DIO_voidSetPinValue(DIO_u8_PORTA , DIO_u8_PIN5 , DIO_u8_HIGH);
				_delay_ms(3000);
				LCD_voidClearDisplay();

				LCD_voidSendString("Welcome");
				_delay_ms(3000);
				LCD_voidClearDisplay();


			LCD_voidSendString("Temp:");
				LCD_voidWriteNumber(Local_u16Temp);
				LCD_voidSendString("  C");
				_delay_ms(3000);
				LCD_voidClearDisplay();


				// TMRS_voidTimer1SetCompareMatchValue(2200);
				 TMRS_voidTimer1SetCompareMatchValue(2000);
				LCD_voidSendString("Door Close");
				LCD_voidGoToPos(1,0);
				LCD_voidSendString("After 5 sec");



				for (time=5;time>0;time--){
				LCD_voidGoToPos(1,13);
				LCD_voidWriteNumber(time);
				_delay_ms(1000);
						                  }

				// TMRS_voidTimer1SetCompareMatchValue(500);
				 TMRS_voidTimer1SetCompareMatchValue(1000);



				DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
				LCD_voidClearDisplay();
				LCD_voidSendString("Password:");


		}
			else {
				LCD_voidClearDisplay();
				_delay_ms(1000);
				LCD_voidSendString("Password Wrong");
				flag++;
				_delay_ms(3000);
				LCD_voidClearDisplay();

				if (flag == 2){
					LCD_voidSendString("Last Try");
				}
				else if (flag < 2){
					LCD_voidSendString("Try Again");
				}

				_delay_ms(3000);
				LCD_voidClearDisplay();
				LCD_voidSendString("Password:");


					}
			if (flag == 3){

				LCD_voidClearDisplay();
				LCD_voidSendString("Buzzer Alerted");
				DIO_voidSetPinValue(DIO_u8_PORTA , DIO_u8_PIN6 , DIO_u8_HIGH);
				DIO_voidSetPinValue(DIO_u8_PORTA , DIO_u8_PIN7 , DIO_u8_HIGH);

				}

	}
}






