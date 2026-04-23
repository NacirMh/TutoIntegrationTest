#pragma once
#include "IRom.h"

class ContentService {
public:
    ContentService(IRom* rom);

    int loadContent();
    void saveContent(int value);

private:
    IRom* _rom;
};