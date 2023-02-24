################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_Motor.c \
../Timer0.c \
../adc.c \
../distance.c \
../gpio.c \
../icu.c \
../lcd.c \
../lm35_sensor.c \
../ultrasonic.c 

OBJS += \
./DC_Motor.o \
./Timer0.o \
./adc.o \
./distance.o \
./gpio.o \
./icu.o \
./lcd.o \
./lm35_sensor.o \
./ultrasonic.o 

C_DEPS += \
./DC_Motor.d \
./Timer0.d \
./adc.d \
./distance.d \
./gpio.d \
./icu.d \
./lcd.d \
./lm35_sensor.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


