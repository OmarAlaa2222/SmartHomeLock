/*
 * Port_Program.c
 *
 *  Created on: May 25, 2023
 *      Author: Lenovo
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "Port_Config.h"
#include "Port_Private.h"
#include "Port_Interface.h"
#include "Port_Register.h"


void PORT_voidInit(void){

	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;

	PORTA=PORTA_INITIAL_VALUE;
	PORTB=PORTB_INITIAL_VALUE;
	PORTC=PORTC_INITIAL_VALUE;
	PORTD=PORTD_INITIAL_VALUE;




}
