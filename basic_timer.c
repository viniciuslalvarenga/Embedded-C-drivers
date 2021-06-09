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
  
/* Includes ------------------------------------------------------------------*/  
#include "basic_timer.h"

/** @brief  TIM2 Overflow Configuration
  * @retval none
  */ 
void Config_Timer2_Overflow(void)
{
    __disable_irq();    
    RCC->APB1ENR |= (1<<0); /* enable tim2 clock */   
    BASIC_TIMx->PSC = BASIC_PSC;
    BASIC_TIMx->ARR = BASIC_ARR;
    BASIC_TIMx->CR1 |= (1<<0);   /*Enabling counter*/
    BASIC_TIMx->DIER |= (1<<0); /*Enable tim2 update interrupt*/
    NVIC_EnableIRQ(TIM2_IRQn);  /*check IRQn_Type struct in stm32 divice ex: stm32l010x4.h */  
    __enable_irq(); 

}

/** @brief  IRQHandler Call
  * @note  The IRQHandler names can be find on startup_stm32 file 
  * 
  * @retval none
  */ 
 void TIM2_IRQHandler(void)
{
 BASIC_TIMx->SR &= ~(1<<0);  /*Clear interrupt flag*/

    
} 


/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/

