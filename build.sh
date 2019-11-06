echo 'build v1.0 - Lucas'
echo 'avr-g++ GPIOPin.cpp main.cpp UART.cpp -mrelax -Wl,--gc-section -DF_CPU=16000000UL -mmcu=atmega328p -o <exec_name>'
if avr-g++ -Os <files> -DF_CPU=16000000UL -mmcu=atmega2560 -o <exec_name>
then
   echo 'avr-objcopy -O ihex -R .eeprom a5_exec a5_exec.hex'
   avr-objcopy -O ihex -R .eeprom <exec_name> <exec_name>.hex
   echo 'sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:a5_exec.hex'
   avrdude -F -V -c arduino -p ATMEGA2560 -P /dev/ttyUSB0 -b 115200 -U flash:w:<exec_name>.hex
   rm <exec_name>.hex
   rm <exec_name>
fi
