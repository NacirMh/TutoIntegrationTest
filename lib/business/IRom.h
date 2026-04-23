#ifndef IROM_H
#define IROM_H

class IRom {
public:
    virtual void writeByte(char address, char value) = 0;
    virtual char readByte(char address) = 0;
};

#endif