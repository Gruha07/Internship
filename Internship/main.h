/* main.h */

#ifndef __MAIN_H
#define __MAIN_H

//#include "stm32f4xx_hal.h"
#include <stdint.h>

/* Dummy peripheral handle structures (for exam purpose) */
typedef struct { uint8_t dummy; } ADC_HandleTypeDef;
typedef struct { uint8_t dummy; } DMA_HandleTypeDef;
typedef struct { uint8_t dummy; } UART_HandleTypeDef;
typedef struct { uint8_t dummy; } TIM_HandleTypeDef;

/* Peripheral handles */
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim2;

/* Function prototypes */
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_DMA_Init(void);
void MX_ADC1_Init(void);
void MX_USART2_UART_Init(void);
void MX_TIM2_Init(void);

/* Callback */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);

#endif
