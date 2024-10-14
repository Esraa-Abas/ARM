/*
 * EXTI_prog.c
 *
 *  Created on: Jul 25, 2023
 *      Author: esraa
 */

#include"include/LIB/stdtypes.h"
#include"include/LIB/BIT_MATH.h"

#include"include/EXTI/EXTI_Int.h"
#include"include/EXTI/EXTI_priv.h"
#include"include/EXTI/EXTI_config.h"

void (*Global_Pfunc) (void);

void MEXTI_voidConfig(EXTI_LINES_e A_u8Line, GPIO_t  *A_Pstr_GPIOx,Sense_Control_e A_enuSenseMode)
{
//mask reg first, by shifting ~15, also replace switch with if
	if(GPIOA==A_Pstr_GPIOx)
	{

	}
	else if(GPIOB==A_Pstr_GPIOx)
	{
		SYSCFG->SYSCFG_EXTICR[A_u8Line/4]|=(1<<(4*(A_u8Line%4)));
	}
	else if(GPIOC==A_Pstr_GPIOx)
	{
		SYSCFG->SYSCFG_EXTICR[A_u8Line/4]|=(2<<(4*(A_u8Line%4)));
	}


switch(A_enuSenseMode)
{
case Falling:
	SET_BIT(EXTI->EXTI_FTSR,A_u8Line);
	CLR_BIT(EXTI->EXTI_RTSR,A_u8Line);
	break;
case rising:
	SET_BIT(EXTI->EXTI_RTSR,A_u8Line);
	CLR_BIT(EXTI->EXTI_FTSR,A_u8Line);
	break;
case any_change:
	SET_BIT(EXTI->EXTI_RTSR,A_u8Line);
	SET_BIT(EXTI->EXTI_FTSR,A_u8Line);
	break;
}
//enable EXTI
	SET_BIT(EXTI->EXTI_IMR,A_u8Line);

}
void MEXTI_voidCallBack(void (*Pfunc) (void))
{
	Global_Pfunc=Pfunc;
}

void MEXTI_voidINT_Disable(EXTI_LINES_e A_u8Line)
{
	CLR_BIT(EXTI->EXTI_IMR,A_u8Line);
}

EXTI0_IRQHandler()
{
	if(Global_Pfunc!=NULL)
	{
		Global_Pfunc();
	}
	//clear INT flag
SET_BIT(EXTI->EXTI_PR,0);
}
