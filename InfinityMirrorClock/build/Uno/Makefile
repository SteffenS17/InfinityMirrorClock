ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/Adafruit_NeoPixel.cpp.o \
	project/ArduinoIO.cpp.o \
	project/ClassicDesign.cpp.o \
	project/InfinityMirrorClock.cpp.o \
	project/RGBDesign.cpp.o \
	project/SpectrumAnalyzer.cpp.o \
	project/utilities.cpp.o \

PLATFORM_CORE_OBJS = \
	core/abi.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/hooks.c.o \
	core/IPAddress.cpp.o \
	core/main.cpp.o \
	core/new.cpp.o \
	core/PluggableUSB.cpp.o \
	core/Print.cpp.o \
	core/Stream.cpp.o \
	core/Tone.cpp.o \
	core/USBCore.cpp.o \
	core/WInterrupts.c.o \
	core/wiring.c.o \
	core/wiring_analog.c.o \
	core/wiring_digital.c.o \
	core/wiring_pulse.c.o \
	core/wiring_pulse.S.o \
	core/wiring_shift.c.o \
	core/WMath.cpp.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/fix_fft/1.0.0/src/fix_fft.cpp.o \
	libraries/SPI/src/SPI.cpp.o \
	libraries/DS3231/1.0.2/DS3231.cpp.o \
	libraries/Wire/src/utility/twi.c.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/HID/src/HID.cpp.o \
	libraries/SoftwareSerial/src/SoftwareSerial.cpp.o \

TARGETS = \
	InfinityMirrorClock.hex \

all: $(TARGETS)

InfinityMirrorClock.hex: InfinityMirrorClock.elf
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./InfinityMirrorClock.elf" "./InfinityMirrorClock.hex"

InfinityMirrorClock.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./InfinityMirrorClock.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-size" -A "./InfinityMirrorClock.elf"

project/Adafruit_NeoPixel.cpp.o: ../../Adafruit_NeoPixel.cpp project/Adafruit_NeoPixel.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/Adafruit_NeoPixel.cpp.d: ;

-include project/Adafruit_NeoPixel.cpp.d 

project/ArduinoIO.cpp.o: ../../ArduinoIO.cpp project/ArduinoIO.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/ArduinoIO.cpp.d: ;

-include project/ArduinoIO.cpp.d 

project/ClassicDesign.cpp.o: ../../ClassicDesign.cpp project/ClassicDesign.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/ClassicDesign.cpp.d: ;

-include project/ClassicDesign.cpp.d 

project/InfinityMirrorClock.cpp.o: ../../InfinityMirrorClock.cpp project/InfinityMirrorClock.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/InfinityMirrorClock.cpp.d: ;

-include project/InfinityMirrorClock.cpp.d 

project/RGBDesign.cpp.o: ../../RGBDesign.cpp project/RGBDesign.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/RGBDesign.cpp.d: ;

-include project/RGBDesign.cpp.d 

project/SpectrumAnalyzer.cpp.o: ../../SpectrumAnalyzer.cpp project/SpectrumAnalyzer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/SpectrumAnalyzer.cpp.d: ;

-include project/SpectrumAnalyzer.cpp.d 

project/utilities.cpp.o: ../../utilities.cpp project/utilities.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

project/utilities.cpp.d: ;

-include project/utilities.cpp.d 


core/abi.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/CDC.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/HardwareSerial0.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/HardwareSerial1.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial2.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/hooks.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/IPAddress.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/main.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/new.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/PluggableUSB.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/Print.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Stream.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/Tone.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/USBCore.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WInterrupts.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/wiring_digital.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/wiring_pulse.S.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/wiring_shift.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WMath.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



libraries/fix_fft/1.0.0/src/fix_fft.cpp.o: C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src/fix_fft.cpp libraries/fix_fft/1.0.0/src/fix_fft.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/fix_fft/1.0.0/src/fix_fft.cpp.d: ;

-include libraries/fix_fft/1.0.0/src/fix_fft.cpp.d

libraries/SPI/src/SPI.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

libraries/DS3231/1.0.2/DS3231.cpp.o: C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2/DS3231.cpp libraries/DS3231/1.0.2/DS3231.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/DS3231/1.0.2/DS3231.cpp.d: ;

-include libraries/DS3231/1.0.2/DS3231.cpp.d

libraries/Wire/src/utility/twi.c.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/Wire/src/Wire.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/HID/src/HID.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src/HID.cpp libraries/HID/src/HID.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/HID/src/HID.cpp.d: ;

-include libraries/HID/src/HID.cpp.d

libraries/SoftwareSerial/src/SoftwareSerial.cpp.o: C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src/SoftwareSerial.cpp libraries/SoftwareSerial/src/SoftwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/steff/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/cores/arduino" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/variants/standard" -I"C:/Users/steff/.arduinocdt/libraries/fix_fft/1.0.0/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SPI/src" -I"C:/Users/steff/.arduinocdt/libraries/DS3231/1.0.2" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire" -I"C:/Users/steff/.arduinocdt/packages/adafruit/hardware/avr/1.4.11/libraries/Wire/utility" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/EEPROM/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/Wire/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/HID/src" -I"C:/Users/steff/.arduinocdt/packages/arduino/hardware/avr/1.6.20/libraries/SoftwareSerial/src" "$<" -o "$@"

libraries/SoftwareSerial/src/SoftwareSerial.cpp.d: ;

-include libraries/SoftwareSerial/src/SoftwareSerial.cpp.d

