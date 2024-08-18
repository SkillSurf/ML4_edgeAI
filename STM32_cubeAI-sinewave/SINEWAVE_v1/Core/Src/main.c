/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "string.h"
#include "ai_datatypes_defines.h"
#include "ai_platform.h"
#include "sinewave.h"
#include "sinewave_data.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  char buf[50];
  int buf_len = 0;
  ai_error err;
  ai_i32 nbatch;
  ai_network_report report;
  float y_val = 0;

  // Chunck of memmory used to hold intermediate values for NN
  ai_u8 activations[AI_SINEWAVE_DATA_ACTIVATIONS_SIZE];
  //ai_u8 weithtsNew[AI_SINEWAVE_DATA_WEIGHTS_SIZE];

  //Buffers used to store input and output tensors
  AI_ALIGNED(4) ai_u8 in_data[AI_SINEWAVE_IN_1_SIZE_BYTES];
  AI_ALIGNED(4) ai_u8 out_data[AI_SINEWAVE_OUT_1_SIZE_BYTES];

  // Pointers to our model
  ai_handle network = AI_HANDLE_NULL;

  /* AI buffer IO handlers */
  ai_buffer *ai_input;
  ai_buffer *ai_output;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_CRC_Init();
  MX_USB_OTG_FS_USB_Init();
  /* USER CODE BEGIN 2 */
  buf_len = sprintf(buf, "\r\n\r\nSTM32 X-Cube-AI test\r\n");
  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);



  /** @brief Initialize network */
  const ai_handle acts[] = { activations };

  err = ai_sinewave_create_and_init(&network, acts, NULL);
  if (err.type != AI_ERROR_NONE) {
	  buf_len = sprintf(buf, "Error: could not create NN instance\r\n");
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
	  //return -1;
  }
  else
  {
	  buf_len = sprintf(buf, "Success in creating NN instance\r\n");
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
  }


  if (ai_sinewave_get_report(network, &report) != true) {
	  buf_len = sprintf(buf, "AI get report error\r\n");
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
  }
  /*
  buf_len = sprintf(buf, "Model name      : ");
  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
  buf_len = sprintf(buf, report.model_name);
  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
  buf_len = sprintf(buf, "\nModel signature : ");
  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
  buf_len = sprintf(buf, report.model_signature);
  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
  */
  ai_input = &report.inputs[0];
  ai_output = &report.outputs[0];

  //link inputs and outputs to the model
  ai_input[0].data = AI_HANDLE_PTR(in_data);
  ai_output[0].data = AI_HANDLE_PTR(out_data);

  // Create instance of neural network
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1){
	  float x = 0.0f;
	  buf_len = sprintf(buf, "\r\n\r\nStarting inference... \r\n");
	  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
	  for (int i = 0 ; i < 628; i++){  // Adjust the number 628 to create more sampling points
		  x = x + 0.01; // 628 x 0.01 = 6.28; Always keep the multiplication to 6.28 to create one sine wave; Try 6280 x 0.001

		  for (uint32_t j = 0; j < AI_SINEWAVE_IN_1_SIZE_BYTES; j++)
			  {
				((ai_float *)in_data)[j] = (ai_float)x;
			  }

		  nbatch = ai_sinewave_run(network, &ai_input[0], &ai_output[0]);
		  if (nbatch != 1) {
			  buf_len = sprintf(buf, "Error: could not run inference\r\n");
			  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);
			}

		  y_val = ((float *)out_data)[0];

		  buf_len = sprintf(buf, "%f \r\n", y_val);

		  HAL_UART_Transmit(&huart3, (uint8_t *)buf, buf_len, 100);

		  HAL_Delay (10);
    }
	  while(1);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
