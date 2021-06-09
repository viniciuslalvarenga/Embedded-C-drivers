/**
  ******************************************************************************
  * @file basic_timer.h
  * @author Vinicius Lopes Alvarenga
  * @version V1.0.0
  * @date  10/10/2020
  * @brief  Basic Timer bare metal setup
  * @note  This file config was setup to stm32L010
  *******************************************************************************
  * @attention
  *
  * Contact information:
  * viniciusl.alvarenga@hotmail.com
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BASIC_TIMER_H
#define __BASIC_TIMER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/ 
#include "stm32l0xx.h"                  // Device header

/* Private macros ------------------------------------------------------------*/

/** @note  CHECK SPECIFIC MCU REFERENCE MANUAL
  * @note  CNT_CLK = TIMx_CLK /(PSC + 1)  
  * @note  PERIOD = 1/CNT_CLK  >>> LOAD VALUE = WANTED_TIME/PERIOD 
  */ 
#define  BASIC_TIMx   (TIM2)
#define  BASIC_PSC    (0U)     
#define  BASIC_ARR    (0xFFFF) 


/*Public functions*/

extern void Config_Timer2_Overflow(void);



#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/

