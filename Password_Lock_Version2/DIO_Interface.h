

/* File Guard */
#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

/*************************************************/
/* Macros for Ports 							 */
/*************************************************/
#define DIO_u8_PORTA  0
#define DIO_u8_PORTB  1
#define DIO_u8_PORTC  2
#define DIO_u8_PORTD  3

/*************************************************/
/* Macros for Pins								 */
/*************************************************/
#define DIO_u8_PIN0   0
#define DIO_u8_PIN1   1
#define DIO_u8_PIN2   2
#define DIO_u8_PIN3   3
#define DIO_u8_PIN4   4
#define DIO_u8_PIN5   5
#define DIO_u8_PIN6   6
#define DIO_u8_PIN7   7

/*************************************************/
/* Macros for Output and input modes			 */
/*************************************************/
#define DIO_u8_OUTPUT   1
#define DIO_u8_INPUT	0

/*************************************************/
/* Macros for Digital Values					 */
/*************************************************/
#define DIO_u8_HIGH     1
#define DIO_u8_LOW		0


/******************************************************************************/
/* Function: DIO_voidInit			                        				  */
/* I/P Parameters: No thing									          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Set the initial direction & value of All pins       	  */
/******************************************************************************/
void DIO_voidInit (void);

/******************************************************************************/
/* Function: DIO_voidSetPinDirection                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Direction			          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given pin				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/* copy_u8PinDirection: DIO_u8_OUTPUT - DIO_u8_INPUT						  */
/******************************************************************************/
void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);


/******************************************************************************/
/* Function: DIO_voidSetPinValue	                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/* copy_u8Value: DIO_u8_HIGH - DIO_u8_LOW		    						  */
/******************************************************************************/
void DIO_voidSetPinValue (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Value);

/******************************************************************************/
/* Function: DIO_u8GetPinValue		                        				  */
/* I/P Parameters: Port ID,  Pin ID							          		  */
/* Returns:it returns u8 value of pin                          				  */
/* Desc:This Function Gets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/******************************************************************************/
u8   DIO_u8GetPinValue (u8 Copy_u8PortId, u8 Copy_u8PinId);


/******************************************************************************/
/* Function: DIO_voidSetPortDirection                        				  */
/* I/P Parameters: Port ID,   Port Direction				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given port			       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinDirection: Set the Direction in hex format 					  */
/******************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);

/******************************************************************************/
/* Function: DIO_voidSetPortValue	                        				  */
/* I/P Parameters: Port ID,   Port Value					          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinValue: Set the Direction in hex format 					  	  */
/******************************************************************************/
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);

/******************************************************************************/
/* Function: DIO_voidGetPortValue	                        				  */
/* I/P Parameters: Port ID									          		  */
/* Returns:it returns u8 value of port                         				  */
/* Desc:This Function Gets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/******************************************************************************/
u8 DIO_voidGetPortValue(u8 copy_u8PortId);


#endif /* End of file */
