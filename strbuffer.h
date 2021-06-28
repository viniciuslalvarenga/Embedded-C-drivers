/**
  ******************************************************************************
  * @file strbuffer.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STRBUFFER_H
#define __STRBUFFER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/ 
#include "stm32l0xx.h"                  // Device header
#include <string.h>
#include "kpad.h"

/* Private macros ------------------------------------------------------------*/
/** @addtogroup Lista_Estatica_Private_Macros
  * @{
  */

/**
  * @brief  Macro used by the struct buffer in order to set an array size
  */

  #define MAXSTR (21U)

 /**
  * @}
  */

/* Exported variables ------------------------------------------------------- */

/* Exported types ------------------------------------------------------------*/

/** @addtogroup static_buffer_Exported_types
  * @{
  */
  
  /**
  * @brief Data struct StrBuff_TypeDef
  * @note This is a static list
  *
  */
typedef struct StrBuff_struct {

    char strbuff[MAXSTR]; 
    uint8_t qnt;

}StrBuff_TypeDef;


 /**
  * @}
  */


/* Exported functions/methods ------------------------------------------------------- */
/** @addtogroup  StrBuff_struct_Exported_Functions
  * @{
  */

/*constructor - destructor*/
 
extern void StrBuff_ctor(StrBuff_TypeDef *const me); 

/*Public functions*/

extern uint8_t StrBuff_getSize(StrBuff_TypeDef const *const me);
extern bool StrBuff_isFull(StrBuff_TypeDef *const me);
extern void StrBuff_eraseBuff(StrBuff_TypeDef *const me); 
extern bool StrBuff_insertAtEnd(StrBuff_TypeDef *const me, Kpad_TypeDef *const me_);
extern const char *StrBuff_getStr(StrBuff_TypeDef *const me);
extern uint32_t StrBuff_atoi(StrBuff_TypeDef *const me);

/*Private functions*/

bool StrBuff_isNum(StrBuff_TypeDef *const me);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT VINICIUS *****END OF FILE*************************/

