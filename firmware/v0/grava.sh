#grava fuses
../avrdude/bin/avrdude -C../avrdude/etc/avrdude.conf -v -pattiny85 -cusbasp -Uefuse:w:0xFF:m -Uhfuse:w:0xD7:m -Ulfuse:w:0xF1:m

#gravar firmware
../avrdude/bin/avrdude -C../avrdude/etc/avrdude.conf -v -pattiny85 -cusbasp -e -Uflash:w:firmware.hex:i

#protege chip
../avrdude/bin/avrdude -C../avrdude/etc/avrdude.conf -v -pattiny85 -cusbasp -Ulock:w:0xFC:m
