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
Password_Lock_Version2.lss \

FLASH_IMAGE += \
Password_Lock_Version2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Password_Lock_Version2.elf secondary-outputs

# Tool invocations
Password_Lock_Version2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Password_Lock_Version2.map -mmcu=atmega32 -o "Password_Lock_Version2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Password_Lock_Version2.lss: Password_Lock_Version2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Password_Lock_Version2.elf  >"Password_Lock_Version2.lss"
	@echo 'Finished building: $@'
	@echo ' '

Password_Lock_Version2.hex: Password_Lock_Version2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Password_Lock_Version2.elf  "Password_Lock_Version2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Password_Lock_Version2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Password_Lock_Version2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Password_Lock_Version2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
