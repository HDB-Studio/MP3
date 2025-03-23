#ifndef SDCardManager_h
#define SDCardManager_h

#include <SD.h>

class SDCardManager {
public:
    void init();
    bool readFile(const char* filename);
};

#endif