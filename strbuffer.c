/**
  ******************************************************************************
  * @file strbuffer.c
  * @author Vinicius Lopes Alvarenga
  * @version V1.0.0
  * @date 24 may 2021
  * @brief string buffer
  * @note 
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
#include "strbuffer.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @addtogroup static_buffer_Public_Functions
  * @{
  */

/**
  * @brief   StrBuff contructor
  * @retval  StrBuff object
  */
void StrBuff_ctor(StrBuff_TypeDef *const me)
{
    memset(me->strbuff,NULL,sizeof(me->strbuff));
    me->qnt = 0;
}

/**
  * @brief Get the number of elements om buffer
  * @param  StrBuff object
  * @retval quantity of elements on buffer
  */

uint8_t StrBuff_getSize(StrBuff_TypeDef const *const me)
{    
    return me->qnt;
}
/**
  * @brief  Check if the StrBuff is Full
  * @param  StrBuff object: specifies an array and quantity
  * @retval bool value true if the array is full else return false
  */

bool StrBuff_isFull(StrBuff_TypeDef *const me)
{
    if (me == NULL) {
        return false;
    }
    return (me->qnt == MAXSTR); /*return true or false*/
}
/**
  * @brief clear the StrBuff
  * @param StrBuff object
  */
void StrBuff_eraseBuff(StrBuff_TypeDef *const me)
{
    memset(me->strbuff,NULL,sizeof(me->strbuff));
    me->qnt = 0;    
} 
/**
  * @brief      Insert a element at the end of the array
  * @param[in]  StrBuff object 
  * @param[in]  Kpad object
  * @retval     bool value true if success, false if object is NULL or Lista is full
  */

bool StrBuff_insertAtEnd(StrBuff_TypeDef *const me, Kpad_TypeDef *const me_)
{
if (me == NULL) {
        return false;
    }
    if (StrBuff_isFull(me)) {
        return false;
    }
    me->strbuff[me->qnt] = me_->kpadkey;
    me->qnt++;
    return true;
}

   
/**
  * @brief return the string on buffer
  * @param StrBuff object 
  * @retval strbuff string on buffer
  */
const char *StrBuff_getStr(StrBuff_TypeDef *const me)
{
  return (me->strbuff);
} 
/**
  * @brief check if the string only contain mumbers
  * @param StrBuff object 
  */

bool StrBuff_isNum(StrBuff_TypeDef *const me)
{
    uint8_t i;
    for (i = 0; i < MAXSTR; i++) {
    
        if ((me->strbuff[i] < '0') || (me->strbuff[i] > '9')) {
            if (me->strbuff[i] != NULL)  {
                return false;
            }
        }
    }    
    return true;
} 

/**
  * @brief convert the string in uint32_t
  * @param StrBuff object  
  * @note its use StrBuff_isNum to check if all elements is a number
  * @note works only with positive values ate the uni32_t max range
  */
uint32_t StrBuff_atoi(StrBuff_TypeDef *const me)
{
    if (StrBuff_isNum(me) == false) {
        return NULL;
    }
   
    uint32_t data =  ((uint32_t)atoi(me->strbuff)); 
    return  data;
    
} 

   
/**
  * @}
  */

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/

