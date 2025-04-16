/*
 * KPD_Program.c
 *
 *  Created on: May 24, 2023
 *      Author: Lenovo
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "DIO_Interface.h"
#include "LCD_Interface.h"


#include "KPD_Config.h"
#include "KPD_Private.h"
#include "KPD_Interface.h"

#define F_CPU  8000000UL
#include <util/delay.h>

	const u8 KPD_Au8Rows[ROW_NUMBER]={KPD_ROW0_PIN ,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	const u8 KPD_Au8Cols[COLUMN_NUMBER]={KPD_COLUMN0_PIN ,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	const u8 KPD_Au8Keys[ROW_NUMBER][COLUMN_NUMBER]= KPD_Arr_Value;

u8 KPD_u8GetPressedKey(void){

	u8 Local_u8RowsCounter , Local_u8ColsCounter , Local_u8Flag=0;


	for(Local_u8RowsCounter=0 ; Local_u8RowsCounter<ROW_NUMBER ; Local_u8RowsCounter++){

		DIO_voidSetPinValue(KPD_Port,KPD_Au8Rows[Local_u8RowsCounter],DIO_u8_LOW);

		for (Local_u8ColsCounter =0 ; Local_u8ColsCounter< COLUMN_NUMBER ; Local_u8ColsCounter++){




			if ( DIO_u8GetPinValue(KPD_Port,KPD_Au8Cols[Local_u8ColsCounter]) == DIO_u8_LOW){
				_delay_ms(20);

				while (DIO_u8GetPinValue(KPD_Port,KPD_Au8Cols[Local_u8ColsCounter]) == DIO_u8_LOW){
					Local_u8Flag=1;

				}
				break;

			}


		}
		DIO_voidSetPinValue(KPD_Port,KPD_Au8Rows[Local_u8RowsCounter],DIO_u8_HIGH);

		if (Local_u8Flag == 1){
			return KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
		}


	}

	return KPD_No_Key_Pressed;

}






