################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/Dio/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
H32_AMIT_MC1.lss \

FLASH_IMAGE += \
H32_AMIT_MC1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: H32_AMIT_MC1.elf secondary-outputs

# Tool invocations
H32_AMIT_MC1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,H32_AMIT_MC1.map -mmcu=atmega16 -o "H32_AMIT_MC1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

H32_AMIT_MC1.lss: H32_AMIT_MC1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S H32_AMIT_MC1.elf  >"H32_AMIT_MC1.lss"
	@echo 'Finished building: $@'
	@echo ' '

H32_AMIT_MC1.hex: H32_AMIT_MC1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex H32_AMIT_MC1.elf  "H32_AMIT_MC1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: H32_AMIT_MC1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 H32_AMIT_MC1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) H32_AMIT_MC1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
