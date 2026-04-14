#Zuerst überlegen was für Ressourcen man hat
#Arduino Uno mit ATmega328P Prozessor und 16 MHZ Takt

SRC = src/LED_BUILTIN.c # einfach nur das ich später SRC eintrag 
MCU = atmega328p
BAUD = 115200
PORT = /dev/ttyACM0
PROGRAMMER = arduino

firmware.elf: $(SRC) #target: dependencies --> unten command: mach aus SRC die datei firmware.elf
	avr-gcc -mmcu=$(MCU) $(SRC) -o firmware.elf  
	
firmware.hex: firmware.elf #mach aus der -elf datei die .hex datei (zum flashen) -R .eeprom heißt remove eeprom
	avr-objcopy -O ihex -R .eeprom $< $@

program: #Hier kein Target mehr, sondern 
	avrdude -p$(MCU) -p $(PORT) -b $(BAUD) -c$(PROGRAMMER) -U flash:w:firmware.hex:a