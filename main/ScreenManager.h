#ifndef ScreenManager_h
#define ScreenManager_h

#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>

class ScreenManager {
public:
    void init();
    void updateDisplay();
private:
    Adafruit_TFTLCD tft;
};

#endif