#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

uint32_t local_time, sensor_time;
uint32_t distance;

__STATIC_INLINE void delay(volatile uint32_t au32_milliseconds);
uint32_t hcsr04_read (void);


int main(void){
	
	
while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
   sensor_time = hcsr04_read();
   distance  = sensor_time * 0.034/2;
		
   HAL_Delay(200);
  }

}
uint32_t hcsr04_read (void)
{
 local_time=0;
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);  // pull the TRIG pin HIGH
 delay(2);  // wait for 2 us


 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);  // pull the TRIG pin HIGH
 delay(10);  // wait for 10 us
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);  // pull the TRIG pin low

 // read the time for which the pin is high

 while (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)));  // wait for the ECHO pin to go high
 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4))    // while the pin is high
  {
  local_time++;   // measure time for which the pin is high
  delay (1);
  }
 return local_time;
}
  
	
	
	 
__STATIC_INLINE void delay(volatile uint32_t au32_milliseconds)
{
  uint32_t au32_initial_ticks = DWT->CYCCNT;
  uint32_t au32_ticks = (HAL_RCC_GetHCLKFreq() / 1000);
  au32_milliseconds *= au32_ticks;
  while ((DWT->CYCCNT - au32_initial_ticks) < au32_milliseconds);
}