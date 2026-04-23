#define ROM_H

#include "Rom.h"
#include <EEPROM.h>
#include "../business/IRom.h"


Rom::Rom(int size) : _size(size) {}

void Rom::begin() {
    EEPROM.begin(_size);
}

void Rom::writeByte(char address, char value) {
    EEPROM.write(address, value);
    EEPROM.commit(); 
}

char Rom::readByte(char address) {
    return EEPROM.read(address);
}