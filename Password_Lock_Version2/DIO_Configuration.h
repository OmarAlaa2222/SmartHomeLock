

/*File Guard*/
#ifndef INCLUDE_MCAL_DIO_DIO_CONFIGURATION_H_
#define INCLUDE_MCAL_DIO_DIO_CONFIGURATION_H_


/*Initial Direction for all pins
 *options DIO_u8_INITIAL_OUTPUT or DIO_u8_INITIAL_INPUT */

/*All Port A Directions Configuration*/
#define DIO_u8_PA0_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA1_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA2_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA3_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA4_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA5_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA6_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA7_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT

/*All Port B Directions Configuration*/
#define DIO_u8_PB0_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB1_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB2_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB3_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB4_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB5_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB6_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PB7_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT

/*All Port C Directions Configuration*/
#define DIO_u8_PC0_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PC1_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PC2_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PC3_INITIAL_DIRECTION            DIO_u8_INITIAL_INPUT
#define DIO_u8_PC4_INITIAL_DIRECTION            DIO_u8_INITIAL_INPUT
#define DIO_u8_PC5_INITIAL_DIRECTION            DIO_u8_INITIAL_INPUT
#define DIO_u8_PC6_INITIAL_DIRECTION            DIO_u8_INITIAL_INPUT
#define DIO_u8_PC7_INITIAL_DIRECTION            DIO_u8_INITIAL_INPUT

/*All Port D Directions Configuration*/
#define DIO_u8_PD0_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD1_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD2_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD3_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD4_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD5_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD6_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD7_INITIAL_DIRECTION            DIO_u8_INITIAL_OUTPUT


/**************************************************************************/
/**************************************************************************/
/*
 * Set Initial value for output pins and set pull up or floating for input pins
 *  DIO_u8_OUTPUT_LOW
    DIO_u8_OUTPUT_HIGH
    DIO_u8_INPUT_FLOATING
    DIO_u8_INPUT_PULLUP
 * */

/*All Port A Values Configuration*/
#define DIO_u8_PA0_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA1_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA2_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA3_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA4_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA5_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA6_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PA7_INITIAL_VALUE            DIO_u8_OUTPUT_LOW

/*All Port B Values Configuration*/
#define DIO_u8_PB0_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB1_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB2_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB3_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB4_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB5_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB6_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PB7_INITIAL_VALUE            DIO_u8_OUTPUT_LOW

/*All Port C Values Configuration*/
#define DIO_u8_PC0_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC1_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC2_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC3_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC4_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC5_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC6_INITIAL_VALUE            DIO_u8_INPUT_FLOATING
#define DIO_u8_PC7_INITIAL_VALUE            DIO_u8_INPUT_FLOATING

/*All Port D Values Configuration*/
#define DIO_u8_PD0_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD1_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD2_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD3_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD4_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD5_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD6_INITIAL_VALUE            DIO_u8_OUTPUT_LOW
#define DIO_u8_PD7_INITIAL_VALUE            DIO_u8_OUTPUT_LOW

#endif /* End of file */
