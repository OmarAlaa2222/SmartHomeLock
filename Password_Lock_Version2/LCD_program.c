/*
 * program.c
 *
 *  Created on: May 15, 2023
 *      Author: Legion
 */


// LIB
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "util/delay.h"

//HAL
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"


//MCAL
#include "DIO_Interface.h"



void LCD_voidSendInstruction(u8 Copy_u8_Instruction){
	// RS PIN LOW for command
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);

	//RW PIN LOW for write
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);

	//SET Command to data
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8_Instruction);

	//Send enable pulse
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);

	_delay_ms(2);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);

}
void LCD_voidSendData(u8 Copy_u8_Data){
	// RS PIN HIGH for data
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH);

	//RW PIN LOW for write
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);

	//SET Command to data
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8_Data);

	//Send enable pulse
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);

	_delay_ms(2);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);
}
void LCD_voidInit(){

	//Wait for more than 30msec
	_delay_ms(40);

	//Function Set Command
	LCD_voidSendInstruction(LCD_u8_FUNCTION_SET);

	_delay_ms(40);

	//Display ON/OFF Control Command
	LCD_voidSendInstruction(LCD_u8_DISPLAY_CONTROL);

	_delay_ms(40);


	LCD_voidSendInstruction(LCD_u8_CLEAR_DISPLAY);

	_delay_ms(40);

	LCD_voidSendInstruction(LCD_u8_ENTRY_MODE);

	_delay_ms(40);
}


void LCD_voidSendString(u8 *Copy_String){
	u8 i;
	for (i=0;Copy_String[i]>0;i++){
		LCD_voidSendData(Copy_String[i]);
	}

}

void LCD_voidClearDisplay(){
	LCD_voidSendInstruction(LCD_u8_CLEAR_DISPLAY);
}


void LCD_voidGoToPos(u8 Copy_u8_XPos,u8 Copy_u8_YPos){
	u8 Local_Address;
	if (Copy_u8_XPos == 0){
		Local_Address=Copy_u8_YPos;
	}
	else if (Copy_u8_XPos == 1){
		Local_Address=Copy_u8_YPos+ 64 ;  // 0x40 because of the start of second row
	}

	LCD_voidSendInstruction(Local_Address+LCD_u8_POSITION);         // 128 because of 1 in instruction data sheet
}


void LCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos){

	u8 Local_u8CGRAM_Address=0,Local_u8_Iterator;

	//Calculate CGRAM Address each block 8 bytes
	Local_u8CGRAM_Address=Copy_u8PatternNumber*8;

	//Send CGRAM Address command to LCD
	LCD_voidSendInstruction(Local_u8CGRAM_Address+64);

	// Write Pattern into CGRAM
	for (Local_u8_Iterator=0;Local_u8_Iterator<8;Local_u8_Iterator++){
		LCD_voidSendData(Copy_u8Pattern[Local_u8_Iterator]);
	}

	LCD_voidGoToPos(Copy_u8XPos,Copy_u8YPos);

	//Display pattern written into the CGRAM

	LCD_voidSendData(Copy_u8PatternNumber);
}



void LCD_voidMyNameAra(){
	u8 arr[8]={0b00000000,
				   0b00000000,
				   0b00000001,
				   0b00000010,
				   0b00011111,
				   0b00000000,
				   0b00000000,
				   0b00000000};

		LCD_voidWriteSpecialCharacter(arr,0,0,8);


		u8 arr1[8]={0b00000000,
				    0b00000000,
				    0b00000111,
					0b00000101,
					0b00011111,
				    0b00000000,
				    0b00000000,
				    0b00000000};

		LCD_voidWriteSpecialCharacter(arr1,1,0,7);


		u8 arr2[8]={0b00000000,
				    0b00000000,
				    0b00000000,
					0b00000000,
					0b00000011,
				    0b00000100,
				    0b00001000,
				    0b00010000};

		LCD_voidWriteSpecialCharacter(arr2,2,0,6);

		u8 arr3[8]={0b00000000,
				   0b00000000,
				   0b00000001,
				   0b00000010,
				   0b00011111,
				   0b00000000,
				   0b00000000,
				   0b00000000};

		LCD_voidWriteSpecialCharacter(arr3,3,0,5);

		u8 arr4[8]={0b00010001,
				    0b00001001,
				    0b00000101,
				    0b00000011,
				    0b00011111,
				    0b00000000,
				    0b00000000,
				    0b00000000};

		LCD_voidWriteSpecialCharacter(arr4,4,0,4);

		u8 arr5[8]={0b00000000,
				   0b00000000,
				   0b00000001,
				   0b00000010,
				   0b00000111,
				   0b00000000,
				   0b00000000,
				   0b00000000};

		LCD_voidWriteSpecialCharacter(arr5,5,0,3);
}


void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	int arr[20];
	int i = 0;
	int j, r;

	// Till N becomes 0
	while (Copy_u32Number != 0) {

		// Extract the last digit of N
		r = Copy_u32Number % 10;

		// Put the digit in arr[]
		arr[i] = r;
		i++;

		// Update N to N/10 to extract
		// next last digit
		Copy_u32Number = Copy_u32Number / 10;

	}

	// Print the digit of N by traversing
	// arr[] reverse
	for (j = i - 1; j > -1; j--)
	{
		char aNumberAsString[20];
		itoa(arr[j],aNumberAsString ,10);
		LCD_voidSendString(aNumberAsString);
	}
}
