/*
 * EXTI_priv.h
 *
 *  Created on: Jul 25, 2023
 *      Author: esraa
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

typedef struct
{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;

}EXTI_t;

typedef struct
{
	volatile u32 SYSCFG_EXTICR[4];

}SYSCFG_t;

#define EXTI ((volatile EXTI_t *)    0x40013C00)
#define SYSCFG ((volatile SYSCFG_t *)0x40013808)

#endif /* EXTI_PRIV_H_ */
