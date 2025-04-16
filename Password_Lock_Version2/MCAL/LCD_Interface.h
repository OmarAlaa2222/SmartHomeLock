/*
 * LCD_Interface.h
 *
 *  Created on: May 15, 2023
 *      Author: Legion
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidSendInstruction(u8 Copy_u8_Instruction);
void LCD_voidSendData(u8 Copy_u8_Data);
void LCD_voidInit();
void LCD_voidSendString(u8 *Copy_String);

void LCD_voidGoToPos(u8 Copy_u8_XPos,u8 Copy_u8_YPos);
void LCD_voidClearDisplay();

void LCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);

void LCD_voidMyNameAra();

void LCD_voidWriteNumber(u32 Copy_u32Number);

#endif /* LCD_INTERFACE_H_ */
