#ifndef BluetoothManager_h
#define BluetoothManager_h

#include <SoftwareSerial.h>

class BluetoothManager {
public:
    BluetoothManager(uint8_t rxPin, uint8_t txPin);
    void init();
    void update();
    bool connectBluetooth();
    void requestWarrantyInfo();

private:
    SoftwareSerial _bluetooth;
    bool _isConnected = false;
};

#endif