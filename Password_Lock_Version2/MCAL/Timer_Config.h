/*
 * Timer_Config.h
 *
 *  Created on: Jul 14, 2023
 *      Author: Lenovo
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
// TIMER 0
// Timer Mode
// NORMAL -- CTC -- FAST_PWM -- PWM_PHASE

#define TMR_MODE0 NORMAL

// if CTC NORMAL -- TOGGLE -- SET - CLEAR  ON COMPARE MATCH
// if Fast PWM  NORMAL -- INVERTING -- NON_INVERTING
// if Phase PWM NORMAL -- INVERTING -- NON_INVERTING

#define TMR_ACTION0 CLEAR

// CLOCK PRE SCALAR No Clk Source - No div - Div by 8 ,64 ,265 ,1024 - Counter Fall / Rise

#define CLK_PreScalar0 DIV_BY_8


#define PRELOAD_VALUE0 192

// TIMER 1


//TIMER CHANNEL A - B

#define CHANNEL A



// Timer Mode (SELECT FROM 0 TO 15 )  FROM DATASHEET PAGE 107


#define TMR_MODE1 MODE_14


// if CTC NORMAL -- TOGGLE -- SET - CLEAR  ON COMPARE MATCH
// if Fast PWM  NORMAL -- INVERTING -- NON_INVERTING
// if Phase PWM NORMAL -- INVERTING -- NON_INVERTING

#define TMR_ACTION1 NON_INVERTING



// CLOCK PRE SCALAR No Clk Source - No div - Div by 8 ,64 ,265 ,1024 - Counter Fall / Rise

#define CLK_PreScalar1 DIV_BY_8


#endif /* TIMER_CONFIG_H_ */
