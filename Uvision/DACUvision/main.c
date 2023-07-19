/*Include header file for STM32F4 HAL libraries and callback functions */
#include "stm32f4xx_hal.h"

/* Function prototype to configure and initialize DAC and GPIO pin */
void configure_DAC(void);
void configure_GPIO(void);
void Delay_ms(volatile int time_ms);

/* create an instance to DAC_HandleTypeDef C struct */
DAC_HandleTypeDef DAC_Config;


/* main function to set DAC numeric value */
int main(void)
{
configure_DAC(); // call DAC initialization and configuration routine
configure_GPIO(); // call GPIO PA5 initialization and configuration routine
	
/* Start DAC conversion with DAC_CHANNEL_2 */
HAL_DAC_Start(&DAC_Config, DAC_CHANNEL_2);
	while(1){
			int D_Value = 1;
	
			while(D_Value < 4095) {
				HAL_DAC_SetValue(&DAC_Config, DAC_CHANNEL_2, DAC_ALIGN_12B_R, D_Value);
				Delay_ms(1);
				D_Value+=100;
				}
		
			while(D_Value > 0) {
				HAL_DAC_SetValue(&DAC_Config, DAC_CHANNEL_2, DAC_ALIGN_12B_R, D_Value);
				Delay_ms(1);
				D_Value-=100;
				}
			}
}

/* Initialize and configure DAC_Channel_2 */
void configure_DAC(void)
{
 DAC_ChannelConfTypeDef Channel_Config;
 __HAL_RCC_DAC_CLK_ENABLE();
 /* DAC Initialization */
 DAC_Config.Instance = DAC;
 HAL_DAC_Init(&DAC_Config);

 /* DAC channel_OUT2 config */
 Channel_Config.DAC_Trigger = DAC_TRIGGER_NONE;
 Channel_Config.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
 HAL_DAC_ConfigChannel(&DAC_Config, &Channel_Config, DAC_CHANNEL_2);
}
/* Initialize and configure GPIO PA4 as a analog pin */
void configure_GPIO(void)
{

/* DAC GPIO ---> PA5 */
 GPIO_InitTypeDef GPIO_InitStruct;
 GPIO_InitStruct.Pin = GPIO_PIN_5;
 GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
/*Generate ms */
void Delay_ms(volatile int time_ms)
{
	      int j;
        for(j = 0; j < time_ms*4000; j++)
            {}  /* excute NOP for 1ms */
}