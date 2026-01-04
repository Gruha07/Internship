/* stm32f4xx_it.c */

#include "main.h"

/* DMA interrupt handler for ADC */
void DMA2_Stream0_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_adc1);
}
