/**
  ******************************************************************************
  * @file debounce.c
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
  
/* Includes ------------------------------------------------------------------*/   
  #include "debounce.h"   

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @addtogroup Debounce_Private_Functions
  * @{
  */

 /**
  * @brief  set debounce_state flag
  * @param  Debounce object
  * @note   privete method used as internal eng
  * @retval None
  */

void Debounce_setState(Debounce_TypeDef *const me)  
{
    me->debounce_state = true; 
}

/**
  * @brief  reset debounce_state flag 
  * @param  Debounce object
  * @note   privete method used as internal eng
  * @retval None
  */   

void Debounce_resetState(Debounce_TypeDef *const me)
{
    me->debounce_state = false;  
} 

/**
  * @brief  read Gpio pin and fix the software input logic base on hardware input.
  * @param  me botton, GPIOx, GPIO_Pin
  * @note   privete method used as internal eng
  * @retval [Moment_state] input register flag
  */

bool Debounce_moment(Debounce_TypeDef const *const me)
{
    bool Moment_state;
    switch(me->pullupdown) {
        
        case false: {           
            Moment_state = HAL_GPIO_ReadPin(me->GPIOx_read, me->GPIO_Pin_read); //extern pull up   
            break;
        }    
        case true: {
            Moment_state = !HAL_GPIO_ReadPin(me->GPIOx_read, me->GPIO_Pin_read); //extern pull up   
            break;
        }   
    }
    
return Moment_state;
    
}

 /**
  * @}
  */

/* Public functions ----------------------------------------------------------*/

/**
  * @addtogroup Debounce_Public_Functions
  * @{
  */

/**
  * @brief  Debounce constructor
  * @retval Debounce object
  */

void Debounce_ctor(Debounce_TypeDef *const me, GPIO_TypeDef *const GPIOx_read, uint16_t const GPIO_Pin_read,
                   DebounceUpDown_Type const PullOnOff, DebounceCicle_Type const DEBOUNCE_Cicle)
{  
    me-> debounce_state = false;
    me->pullupdown = PullOnOff;  
    me->State = 0x0000; 
    me->DEBOUNCE_CICLE = DEBOUNCE_Cicle;  
    me->GPIOx_read = GPIOx_read;
    me->GPIO_Pin_read = GPIO_Pin_read;    
}

/**
  * @brief  Debounce processing method Engineer
  * @param  Debounce object
  * @note   This process set/reset debounce_state
  */

void Debounce_processing(Debounce_TypeDef *const me)
{  
    bool Moment_state = Debounce_moment(me);    
    me->State = ((me->State | Moment_state)<<1);   
    
    if ((me->State & me->DEBOUNCE_CICLE) == me->DEBOUNCE_CICLE) {
        Debounce_setState(me); 
    }
    if ((me->State & me->DEBOUNCE_CICLE) == 0x0000) {    
        Debounce_resetState(me);
    }    
}

/**
  * @brief  Check if debounce is complet
  * @param  Debounce object
  * @retval debounce_state
  */

bool Debounce_isProcessed(Debounce_TypeDef const *const me)
{
    return (me->debounce_state);
}   

 /**
  * @}
  */

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/

