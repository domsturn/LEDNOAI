#! /bin/bash 

set -e
avrdude -p ATmega328p -P /dev/ttyACM0 -b 115200 -c arduino -U flash:w:firmware.hex:a