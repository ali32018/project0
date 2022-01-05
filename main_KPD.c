/*
 * main.c
 *
 *  Created on: Dec 25, 2021
 *      Author: ali
 */

#include"lib/BIT_MATH.h"
#include"lib/std.types.h"
#include"MCAL/01-DIO/DIO_interface.h"
#include"HAL/LCD/LCD_interface.h"
#include<util/delay.h>



int main (){

	u8 Key;
	/*column as output*/

	DIO_VidSetPinDirection(PORT_A, PIN_0 , OUTPUT) ;
	DIO_VidSetPinDirection(PORT_A, PIN_1 , OUTPUT) ;
	DIO_VidSetPinDirection(PORT_A, PIN_2 , OUTPUT) ;
	DIO_VidSetPinDirection(PORT_A, PIN_3 , OUTPUT) ;

	/*row as input*/

   DIO_VidSetPinDirection(PORT_A, PIN_4 , INPUT) ;
   DIO_VidSetPinDirection(PORT_A, PIN_5 , INPUT) ;
   DIO_VidSetPinDirection(PORT_A, PIN_6 ,  INPUT) ;
   DIO_VidSetPinDirection(PORT_A, PIN_7 , INPUT) ;

   /*set as pull up*/


   DIO_VidSetPinDirection(PORT_A, PIN_4 , HIGH) ;
   DIO_VidSetPinDirection(PORT_A, PIN_5 , HIGH) ;
   DIO_VidSetPinDirection(PORT_A, PIN_6 , HIGH) ;
   DIO_VidSetPinDirection(PORT_A, PIN_7 , HIGH) ;


   DIO_VidSetPortDirection(PORT_B , OUTPUT);

   DIO_VidSetPortDirection(PORT_C, OUTPUT);
  	   DIO_VidSetPinValue(PORT_C ,PIN_1, HIGH);
  	   _delay_ms(10000);
         DIO_VidSetPinValue(PORT_C ,PIN_1,LOW);


      Key= KPD_u8GetPressedKey();



	   DIO_VidSetPinValue(PORT_B ,Key, HIGH);
	   DIO_VidSetPortDirection(PORT_C, OUTPUT);
	   DIO_VidSetPinValue(PORT_C ,PIN_1, HIGH);
	   _delay_ms(10000);
       DIO_VidSetPinValue(PORT_B ,Key,LOW);
       while(1){
   }
}
