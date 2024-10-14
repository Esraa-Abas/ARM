/*
 * EXTI_Int.h
 *
 *  Created on: Jul 25, 2023
 *      Author: esraa
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include"../LIB/stdtypes.h"
#include""

typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15
}EXTI_LINES_e;

typedef enum
{
	Falling,
	rising,
	any_change
}Sense_Control_e;

void MEXTI_voidConfig(EXTI_LINES_e A_u8Line, GPIO_t  *A_Pstr_GPIOx,Sense_Control_e A_enuSenseMode);
void MEXTI_voidCallBack(void (*Pfunc) (void));
void MEXTI_voidINT_Disable(EXTI_LINES_e A_u8Line);


#endif /* EXTI_INT_H_ */
