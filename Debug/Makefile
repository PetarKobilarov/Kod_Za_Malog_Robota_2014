################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../can.c \
../crvenaStrana.c \
../detekcijaProtivnika.c \
../novi2014.c \
../odometry.c \
../system.c \
../timers.c \
../usart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
can.o \
crvenaStrana.o \
detekcijaProtivnika.o \
novi2014.o \
odometry.o \
system.o \
timers.o \
usart.o

OBJS_AS_ARGS +=  \
can.o \
crvenaStrana.o \
detekcijaProtivnika.o \
novi2014.o \
odometry.o \
system.o \
timers.o \
usart.o

C_DEPS +=  \
can.d \
crvenaStrana.d \
detekcijaProtivnika.d \
novi2014.d \
odometry.d \
system.d \
timers.d \
usart.d

C_DEPS_AS_ARGS +=  \
can.d \
crvenaStrana.d \
detekcijaProtivnika.d \
novi2014.d \
odometry.d \
system.d \
timers.d \
usart.d

OUTPUT_FILE_PATH +=novi2014.elf

OUTPUT_FILE_PATH_AS_ARGS +=novi2014.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler

















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.3.3
	$(QUOTE)C:\WinAVR-20100110\bin\avr-gcc.exe$(QUOTE)  -x c -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic-errors -mmcu=at90can128 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.3.3
	$(QUOTE)C:\WinAVR-20100110\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="novi2014.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=at90can128  
	@echo Finished building target: $@
	"C:\WinAVR-20100110\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "novi2014.elf" "novi2014.hex"
	"C:\WinAVR-20100110\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "novi2014.elf" "novi2014.eep" || exit 0
	"C:\WinAVR-20100110\bin\avr-objdump.exe" -h -S "novi2014.elf" > "novi2014.lss"
	"C:\WinAVR-20100110\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "novi2014.elf" "novi2014.srec"
	"C:\WinAVR-20100110\bin\avr-size.exe" "novi2014.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "novi2014.elf" "novi2014.a" "novi2014.hex" "novi2014.lss" "novi2014.eep" "novi2014.map" "novi2014.srec" "novi2014.usersignatures"
	