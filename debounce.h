/**
  ******************************************************************************
  * @file debounce.h
  * @author Vinicius Lopes Alvarenga
  * @version V1.0.0
  * @date 17 may 2021
  * @brief This is an On Off peripheral device handler
  * @note This drive use stm32 HAL library 
  *******************************************************************************
  * @attention
  *
  * Copyright (C) 2021-2036 Vinicius Lopes Alvarenga. All rights reserved.
  *
  * This program is open source software: you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as published
  * by the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program. If not, see <www.gnu.org/licenses>.
  *
  * Contact information:
  * viniciusl.alvarenga@hotmail.com
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEBOUNCE_H
#define __DEBOUNCE_H

#ifdef __cplusplus
 extern "C" {
#endif
 
/* Includes ------------------------------------------------------------------*/ 
#include "stm32l0xx.h"                  // Device header
#include <stdbool.h>
#include <stdlib.h>

/* Exported variables ------------------------------------------------------- */

/* Exported types ------------------------------------------------------------*/

/** @addtogroup Debounce_Exported_types
  * @{
  */

  /**
  * @brief  Definition of number of cicle to debounce return true. Used by the @ref Debounce_ctor 
  *         @ref Debounce_processing.
  */
  
typedef enum {
    
    DEBOUNCE_CICLE_3  = (0X001EU),  /* 0000 0000 0001 1110 */ 
    DEBOUNCE_CICLE_4  = (0X003EU),  /* 0000 0000 0011 1110 */ 
    DEBOUNCE_CICLE_5  = (0X007EU),  /* 0000 0000 0111 1110 */ 
    DEBOUNCE_CICLE_6  = (0X00FEU),  /* 0000 0000 1111 1110 */ 
    DEBOUNCE_CICLE_7  = (0X01FEU),  /* 0000 0001 1111 1110 */ 
    DEBOUNCE_CICLE_8  = (0X03FEU),  /* 0000 0011 1111 1110 */ 
    DEBOUNCE_CICLE_9  = (0X07FEU),  /* 0000 0111 1111 1110 */ 
    DEBOUNCE_CICLE_10 = (0X0FFEU),  /* 0000 1111 1111 1110 */ 
    DEBOUNCE_CICLE_11 = (0X1FFEU),  /* 0001 1111 1111 1110 */ 
    DEBOUNCE_CICLE_12 = (0X3FFEU),  /* 0011 1111 1111 1110 */ 
    DEBOUNCE_CICLE_13 = (0X7FFEU),  /* 0111 1111 1111 1110 */ 
    DEBOUNCE_CICLE_14 = (0XFFFEU)   /* 1111 1111 1111 1110 */ 
    
}DebounceCicle_Type;

  /**
  * @brief Initial Hardware status
  *
  */

typedef enum {
    
    PULL_DOWN = (0U),  
    PULL_UP   = (1U)
    
}DebounceUpDown_Type;

/**
  * @brief  Data struct Debounce_TypeDef
  * @param  [debounce_state] control flag @ref Debounce_processing @ref Debounce_setState
  *         @ref Debounce_resetState @ref Debounce_isDone.                
  * @param  [pullupdown] fix the software logic based on hardware input logic @ref Debounce_moment
  * @param  [State] @ref Debounce_processing internal counting
  * @param  [DEBOUNCE_CICLE] number of debounce cicle [state] count to make debounce_state true.
  * @param  [GPIOx_read] gpio port [A-F]
  * @param  [GPIO_Pin_read] gpio pin [0-15]
  *
  */   

typedef struct Debounce_struct {
    
    volatile bool debounce_state;
    DebounceUpDown_Type pullupdown; 
    volatile uint16_t State; 
    DebounceCicle_Type DEBOUNCE_CICLE; 
    GPIO_TypeDef *GPIOx_read;
    uint16_t GPIO_Pin_read;   
  
}Debounce_TypeDef;
    
/**
  * @}
  */


/* Exported functions/methods ------------------------------------------------------- */
/** @addtogroup Debounce_Exported_Functions
  * @{
  */

/*constructor - destructor*/
extern void Debounce_ctor(Debounce_TypeDef *const me, GPIO_TypeDef *const GPIOx_read, uint16_t const GPIO_Pin_read,
                   DebounceUpDown_Type const PullOnOff, DebounceCicle_Type const DEBOUNCE_Cicle);

/*Public methods*/

extern void Debounce_processing(Debounce_TypeDef *const me);
extern bool Debounce_isProcessed(Debounce_TypeDef const *const me);

/**
  * @}
  */

/* Protected functions/methods ------------------------------------------------------- */
/** @addtogroup Debounce_Protected_Functions
  * @{
  */
void Debounce_setState(Debounce_TypeDef *const me);  
void Debounce_resetState(Debounce_TypeDef *const me);
bool Debounce_moment(Debounce_TypeDef const *const me);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/
