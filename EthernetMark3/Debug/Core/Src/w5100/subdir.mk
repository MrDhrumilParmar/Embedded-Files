################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/w5100/socket.c \
../Core/Src/w5100/w5100_spi.c \
../Core/Src/w5100/wizchip_conf.c 

OBJS += \
./Core/Src/w5100/socket.o \
./Core/Src/w5100/w5100_spi.o \
./Core/Src/w5100/wizchip_conf.o 

C_DEPS += \
./Core/Src/w5100/socket.d \
./Core/Src/w5100/w5100_spi.d \
./Core/Src/w5100/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/w5100/%.o Core/Src/w5100/%.su Core/Src/w5100/%.cyclo: ../Core/Src/w5100/%.c Core/Src/w5100/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I../Core/Src/w5100 -I../Core/Src/w5100/W5100 -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-w5100

clean-Core-2f-Src-2f-w5100:
	-$(RM) ./Core/Src/w5100/socket.cyclo ./Core/Src/w5100/socket.d ./Core/Src/w5100/socket.o ./Core/Src/w5100/socket.su ./Core/Src/w5100/w5100_spi.cyclo ./Core/Src/w5100/w5100_spi.d ./Core/Src/w5100/w5100_spi.o ./Core/Src/w5100/w5100_spi.su ./Core/Src/w5100/wizchip_conf.cyclo ./Core/Src/w5100/wizchip_conf.d ./Core/Src/w5100/wizchip_conf.o ./Core/Src/w5100/wizchip_conf.su

.PHONY: clean-Core-2f-Src-2f-w5100

