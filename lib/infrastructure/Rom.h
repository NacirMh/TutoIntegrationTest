
#include "../business/IRom.h"

class Rom : public IRom {
public:
    Rom(int size);
    void begin();

    void writeByte(char address, char value) override;
    char readByte(char address) override;

private:
    int _size;
};