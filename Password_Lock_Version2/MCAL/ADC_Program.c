/*
 * ADC_Program.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Register.h"

static void (*ADC_pfNotification)(void)= NULL;

static u8 ADC_u8BusyFlag =0;        //static not to change any file to change  this variable
static u8 ADMUX_CHANNEL_NUM_MASK=0;
void ADC_voidInit(void){
u8 Local_u8_ADMUX=0b00000000;

	// Select Voltage Reference

#if Voltage_Reference == AREF
	CLR_BIT(Local_u8_ADMUX,ADMUX_REFS1);
	CLR_BIT(Local_u8_ADMUX,ADMUX_REFS0);

#elif Voltage_Reference == AVCC
	CLR_BIT(Local_u8_ADMUX,ADMUX_REFS1);
	SET_BIT(Local_u8_ADMUX,ADMUX_REFS0);

#elif Voltage_Reference == Internal
	SET_BIT(Local_u8_ADMUX,ADMUX_REFS1);
	SET_BIT(Local_u8_ADMUX,ADMUX_REFS0);

#endif

// Selecting ADC Adjustment
#if ADC_ADJUST == RIGHT

	CLR_BIT(Local_u8_ADMUX,ADMUX_ADLAR);

#elif ADC_ADJUST == LEFT

	SET_BIT(Local_u8_ADMUX,ADMUX_ADLAR);

#endif


// Selecting ADC_PreScalar

#if ADC_PreScalar == 2
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 4
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);


#elif ADC_PreScalar == 8
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 16
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 32
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);


#elif ADC_PreScalar == 64
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

#elif ADC_PreScalar == 128
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);


#endif

    //Disable AutoTrigger
	CLR_BIT(ADCSRA,ADCSRA_ADATE);



	//Enable ADC

	SET_BIT(ADCSRA,ADCSRA_ADEN);


	ADMUX=Local_u8_ADMUX;

}


u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb){

	// ADMUX |=(ADMUX_CHANNEL_NUM_MASK);
	ADMUX |=Copy_u8ChannelNb;

	//START CONVERSION
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	//POLLING ON FLAG

	while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

		// CLEAR FLAG
		SET_BIT(ADCSRA,ADCSRA_ADIF);

		//READ ADC VALUE

		u16 res= ADCL | (ADCH << 8) ;  // Reading Both Regs

		return res;

}

void ADC_voidGetDigitalValueAsynch(u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(void)) {

	if (ADC_u8BusyFlag==0 && Copy_pfNotification!= NULL){
	// ADMUX &=(ADMUX_CHANNEL_NUM_MASK);
	ADMUX |=Copy_u8ChannelNb;

	//Set Flag to make ADC is busy

	ADC_u8BusyFlag=1;

	// Update Global Pointer to a function
	ADC_pfNotification=Copy_pfNotification;

	//Enable ADC Interrupt
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	//START CONVERSION
	SET_BIT(ADCSRA,ADCSRA_ADSC);




	}


}

void __vector_16(void) /* From VECTOR TABLE */           __attribute__((signal)); /* Attribute signal to protect from the compiler from optimization*/
void __vector_16(void)
{
	if (ADC_pfNotification!= NULL){
		//Clear Busy Flag
		ADC_u8BusyFlag=0;
		//Disable ADC Interrupt
		CLR_BIT(ADCSRA,ADCSRA_ADIE);

		// Calling Notification Function
		ADC_pfNotification();




	}
}


u16 ADC_u16GetADCRegValue (void){

	return ADC_REG;

}



