################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aufgabenblock_2.cpp \
../src/Fahrrad.cpp \
../src/Fahrzeug.cpp \
../src/PKW.cpp \
../src/Simulationsobjekt.cpp \
../src/Verhalten.cpp \
../src/Weg.cpp 

CPP_DEPS += \
./src/Aufgabenblock_2.d \
./src/Fahrrad.d \
./src/Fahrzeug.d \
./src/PKW.d \
./src/Simulationsobjekt.d \
./src/Verhalten.d \
./src/Weg.d 

OBJS += \
./src/Aufgabenblock_2.o \
./src/Fahrrad.o \
./src/Fahrzeug.o \
./src/PKW.o \
./src/Simulationsobjekt.o \
./src/Verhalten.o \
./src/Weg.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I/Users/kekillialiresid/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Aufgabenblock_2.d ./src/Aufgabenblock_2.o ./src/Fahrrad.d ./src/Fahrrad.o ./src/Fahrzeug.d ./src/Fahrzeug.o ./src/PKW.d ./src/PKW.o ./src/Simulationsobjekt.d ./src/Simulationsobjekt.o ./src/Verhalten.d ./src/Verhalten.o ./src/Weg.d ./src/Weg.o

.PHONY: clean-src

