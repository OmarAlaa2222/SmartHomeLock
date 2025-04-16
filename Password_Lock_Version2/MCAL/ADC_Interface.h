/*
 * ADC_Interface.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Lenovo
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_u8_ADC_Channel_0  0
#define ADC_u8_ADC_Channel_1  1
#define ADC_u8_ADC_Channel_2  2
#define ADC_u8_ADC_Channel_3  3
#define ADC_u8_ADC_Channel_4  4
#define ADC_u8_ADC_Channel_5  5
#define ADC_u8_ADC_Channel_6  6
#define ADC_u8_ADC_Channel_7  7

// To be expanded to 32 CHANNELS




void ADC_voidInit(void);                           //ADC initialization
u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb);   // Read From ADC Channel

u16 ADC_u16GetADCRegValue (void);

void ADC_voidGetDigitalValueAsynch(u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(void));   // Conversion in Asynch function (Start convertion Asynch)  (Enabling Interrupt to start Conversion)



#endif /* ADC_INTERFACE_H_ */
