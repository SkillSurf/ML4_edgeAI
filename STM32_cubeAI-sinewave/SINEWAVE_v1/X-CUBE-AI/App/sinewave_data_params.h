/**
  ******************************************************************************
  * @file    sinewave_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2024-08-12T01:05:54-0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef SINEWAVE_DATA_PARAMS_H
#define SINEWAVE_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_SINEWAVE_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_sinewave_data_weights_params[1]))
*/

#define AI_SINEWAVE_DATA_CONFIG               (NULL)


#define AI_SINEWAVE_DATA_ACTIVATIONS_SIZES \
  { 128, }
#define AI_SINEWAVE_DATA_ACTIVATIONS_SIZE     (128)
#define AI_SINEWAVE_DATA_ACTIVATIONS_COUNT    (1)
#define AI_SINEWAVE_DATA_ACTIVATION_1_SIZE    (128)



#define AI_SINEWAVE_DATA_WEIGHTS_SIZES \
  { 1284, }
#define AI_SINEWAVE_DATA_WEIGHTS_SIZE         (1284)
#define AI_SINEWAVE_DATA_WEIGHTS_COUNT        (1)
#define AI_SINEWAVE_DATA_WEIGHT_1_SIZE        (1284)



#define AI_SINEWAVE_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_sinewave_activations_table[1])

extern ai_handle g_sinewave_activations_table[1 + 2];



#define AI_SINEWAVE_DATA_WEIGHTS_TABLE_GET() \
  (&g_sinewave_weights_table[1])

extern ai_handle g_sinewave_weights_table[1 + 2];


#endif    /* SINEWAVE_DATA_PARAMS_H */
