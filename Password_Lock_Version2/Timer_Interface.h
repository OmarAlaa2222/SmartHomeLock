/*
 * Timer_Inteface.h
 *
 *  Created on: Jul 14, 2023
 *      Author: Lenovo
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TMRS_voidTMR0Init(void);
void TMRS_voidTimer0SetCallBack(void (*Copy_pf) (void) );

void TMRS_voidTimer0SetCompareMatchValue(u8 Copy_u8_Value);

void TMRS_voidTimer1SetCallBack(void (*Copy_pf) (void));

void TMRS_voidTMR1Init(void);

void TMRS_voidTimer1SetCompareMatchValue(u16 Copy_u8OCR1Value);

void TMRS_voidTimer1SetOverflowValue(u16 Copy_u8ICR1Value);

void ServoSwing (u8 Copy_u8ServoAngle);


#endif /* TIMER_INTERFACE_H_ */
