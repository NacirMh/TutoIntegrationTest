#include "ContentService.h"
#include <cstdint>

void ContentService::saveContent(int value) {
    // store int as 4 bytes
    for (int i = 0; i < sizeof(int); i++) {
        uint8_t byte = (value >> (8 * i)) & 0xFF;
        _rom->writeByte(i, byte);
    }
}

int ContentService::loadContent() {
    int value = 0;

    for (int i = 0; i < sizeof(int); i++) {
        value |= (_rom->readByte(i) << (8 * i));
    }

    return value;
}