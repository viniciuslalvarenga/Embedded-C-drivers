/**
  ******************************************************************************
  * @file botton.h
  * @author Vinicius Lopes Alvarenga
  * @version V1.0.0
  * @date 18 may 2021
  * @brief This is an asynchronous botton handler
  * @note This class use debounce as super class (inheritance)
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
#ifndef __BOTTON_H
#define __BOTTON_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "debounce.h"  /*super class*/ 
#include "buzzer.h"

/* Macros ------------------------------------------------------------*/



/* Exported types ------------------------------------------------------------*/

/** @addtogroup Botton_Exported_types
  * @{
  */

  /**
  * @brief  three state flag to control de botton status. Control one time click.
  *
  */
  
typedef enum {   
    
    BOTTON_PROCESSED   = (0U),  
    BOTTON_NEW_PROCESS = (1U),
    BOTTON_PROCESSING  = (2U)
    
}BottonProcess_Type;

/**
  * @brief  Data struct Botton_TypeDef
  * @param  [super] Debounce_TypeDef  - super class    
  * @param  [BottonProcess] Three stage flag, look's @ref Botton_processing until botton be release
  *        
  */        
typedef struct Botton_struct {
    
    Debounce_TypeDef super;
    volatile BottonProcess_Type BottonProcess;   
    
}Botton_TypeDef;

/**
  * @}
  */

/* Exported functions/methods ------------------------------------------------------- */
/** @addtogroup Botton_Exported_Functions
  * @{
  */

/*constructor - destructor*/
extern void Botton_ctor(Botton_TypeDef *const me, GPIO_TypeDef *const GPIOx_read, uint16_t const GPIO_Pin_read,
                 DebounceUpDown_Type const PullOnOff, DebounceCicle_Type const DEBOUNCE_Cicle);

/*Public methods*/

extern void Botton_processing(Botton_TypeDef *const me);
extern bool Botton_isOnceProcess(Botton_TypeDef *const me);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/
