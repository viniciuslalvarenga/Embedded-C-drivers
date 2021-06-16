/**
  ******************************************************************************
  * @file botton.c
  * @author Vinicius Lopes Alvarenga
  * @version V1.0.0
  * @date 18 may 2021
  * @brief This is an asynchronous botton handler
  * @note This class use debounce as super class (inheritance)
  * 
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
#include "botton.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @addtogroup Botton_Public_Functions
  * @{
  */

/**
  * @brief  Botton constructor
  * @retval Botton object
  */

void Botton_ctor(Botton_TypeDef *const me, GPIO_TypeDef *const GPIOx_read, uint16_t const GPIO_Pin_read,
                 DebounceUpDown_Type const PullOnOff, DebounceCicle_Type const DEBOUNCE_Cicle)
{
    
    Debounce_ctor(&me->super, GPIOx_read, GPIO_Pin_read, PullOnOff, DEBOUNCE_Cicle);
    me->BottonProcess = BOTTON_NEW_PROCESS;     
   
}

/**
  * @brief  Botton processing method Engineer
  * @param  Botton object
  * @note   This process set/reset debounce_state
  * @note   process will be locked until hit @ref Botton_isOnceProcess and botton be released 
  */
void Botton_processing(Botton_TypeDef *const me)
{  
    
    bool Moment_state = Debounce_moment(&me->super);    
    me->super.State = ((me->super.State | Moment_state)<<1); 
  
    if (((me->super.State & me->super.DEBOUNCE_CICLE) == me->super.DEBOUNCE_CICLE)
                                    && (me->BottonProcess == BOTTON_NEW_PROCESS)) {
                                  
        Debounce_setState(&me->super);
        me->BottonProcess = BOTTON_PROCESSING; 
      //  Buzzer_Timer(BOT_BUZZ_TIME);                                        
    }
                                
    if(((me->super.State & me->super.DEBOUNCE_CICLE) == 0x0000) && (me->BottonProcess == BOTTON_PROCESSED)) {   
        
        Debounce_resetState(&me->super);
        me->BottonProcess =  BOTTON_NEW_PROCESS; 
    }    
}

/**
  * @brief  Check if Botton debounce is complet
  * @param  Botton object
  * @note   It's look @ref Botton_processing until botton be release
  * @retval debounce_state
  */

bool Botton_isOnceProcess(Botton_TypeDef *const me)
{
    if (((me->BottonProcess) == BOTTON_PROCESSING) && ((me->super.debounce_state) == true)) { 
        
        me->BottonProcess = BOTTON_PROCESSED; 
        return  true;    
    }
    
return false;
    
} 

 

/**
  * @}
  */

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/


