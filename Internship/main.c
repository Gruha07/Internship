/* main.c
   STM32 Black Pill (Exam Logic Code)
   100Hz Timer → ADC → DMA → UART
*/

#include "main.h"
#include <stdio.h>

/* Dummy peripheral instances */
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
UART_HandleTypeDef huart2;
TIM_HandleTypeDef htim2;

/* ADC buffer */
uint16_t adc_value;
char uart_buf[50];

int main(void)
{
    /* Peripheral initialization (logical) */
    SystemClock_Config();
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_ADC1_Init();
    MX_USART2_UART_Init();
    MX_TIM2_Init();

    /* Simulate periodic timer trigger */
    while (1)
    {
        /* Timer overflow triggers ADC */
        adc_value = 1234;   /* Example ADC value */

        /* DMA transfer complete */
        HAL_ADC_ConvCpltCallback(&hadc1);
    }
}

/* ADC DMA complete callback */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    int len = sprintf(uart_buf,
                      "ADC Value: %d\r\n",
                      adc_value);

    /* Simulated UART transmission */
    for (int i = 0; i < len; i++)
    {
        putchar(uart_buf[i]);   /* Appears on terminal */
    }
}
/* ===== Stub functions (IMPORTANT) ===== */

void SystemClock_Config(void) {}
void MX_GPIO_Init(void) {}
void MX_DMA_Init(void) {}
void MX_ADC1_Init(void) {}
void MX_USART2_UART_Init(void) {}
void MX_TIM2_Init(void) {}
