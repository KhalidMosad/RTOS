################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
AVR_FREERTOS2.lss \

FLASH_IMAGE += \
AVR_FREERTOS2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_FREERTOS2.elf secondary-outputs

# Tool invocations
AVR_FREERTOS2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_FREERTOS2.map -mmcu=atmega32 -o "AVR_FREERTOS2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_FREERTOS2.lss: AVR_FREERTOS2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_FREERTOS2.elf  >"AVR_FREERTOS2.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_FREERTOS2.hex: AVR_FREERTOS2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_FREERTOS2.elf  "AVR_FREERTOS2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_FREERTOS2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_FREERTOS2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_FREERTOS2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
