/*
 * ADC_Register.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Lenovo
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_


#define ADMUX  *((volatile u8*)0x27)

#define ADMUX_REFS1 7
#define ADMUX_REFS0 6
#define ADMUX_ADLAR 5

// #define ADMUX_CHANNEL_NUM_MASK 0b11100000

#define ADCSRA *((volatile u8*)0x26)

#define ADCSRA_ADEN  7
#define ADCSRA_ADSC  6
#define ADCSRA_ADATE 5
#define ADCSRA_ADIF  4
#define ADCSRA_ADIE  3
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0


#define ADCL   *((volatile u8*)0x24)
#define ADCH   *((volatile u8*)0x25)

#define ADC_REG  *((volatile u16*)0x24)


#endif /* ADC_REGISTER_H_ */
