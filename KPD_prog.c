#include  "../../lib/BIT_MATH.h"
#include  "../../lib/std.types.h"
#include  "../../MCAL/01-DIO/DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"

/*
u8 KPD_u8GetPressedKey(void){
	u8 Local_PressedKey= KEY_NOT_PRESSED;

	u8 KPAD_u8State=1;
	u8 KPAD_u8ColumnArray[]= {KPD_C0_PIN, KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN};
	u8 KPAD_u8RowArray[]= {KPD_R0_PIN, KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN};
	u8 user_array [4][4]= USER_NUMBERS;

	for (u8 col=0; col<4; col++){
		DIO_VidSetPinValue(KPD_PORT,KPAD_u8ColumnArray[col],LOW);

		for(u8 row=0; row<4; row++){
			KPAD_u8State=DIO_U8GetPinValue(KPD_PORT,KPAD_u8RowArray[row]);
			if(!KPAD_u8State){
				Local_PressedKey=user_array[col][row];
				while(!KPAD_u8State){
					u8 KPAD_u8State=DIO_U8GetPinValue(KPD_PORT,KPAD_u8RowArray[row]);
				}
				break;
			}
		}
		DIO_VidSetPinValue(KPD_PORT,KPAD_u8ColumnArray[col],HIGH);
		if(Local_PressedKey!=KEY_NOT_PRESSED)break;
	}

	return Local_PressedKey;
}

*/

u8 KPD_u8GetPressedKey(void){

	u8 Local_u8PressedKey = KEY_NOT_PRESSED ;
	u8 state=1;
	u8 user_array [4][4] = USER_NUMBERS ;
	u8 KPD_u8ColumnArray []={KPD_C0_PIN, KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN};
	u8 KPD_u8RowArray [] = {KPD_R0_PIN, KPD_R1_PIN,  KPD_R2_PIN, KPD_R3_PIN} ;

	for (u8 col=0 ; col<4 ; col ++ )
	{
		DIO_VidSetPinValue(KPD_PORT , KPD_u8ColumnArray[col], LOW);
		for (u8 row =0 ; row <4 ; row++){
			state=	DIO_U8GetPinValue(KPD_PORT, KPD_u8RowArray[row]);

			if (state==0) {
				Local_u8PressedKey= user_array[col][row] ;
				while (!state){
					state =DIO_U8GetPinValue(KPD_PORT, KPD_u8RowArray[row]);
				}

				DIO_VidSetPinValue(KPD_PORT , KPD_u8ColumnArray[col], HIGH);

				}
			}
		DIO_VidSetPinValue(KPD_PORT , KPD_u8ColumnArray[col], HIGH);
		}
	return Local_u8PressedKey;
}

