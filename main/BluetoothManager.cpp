#include "BluetoothManager.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

BluetoothManager::BluetoothManager(uint8_t rxPin, uint8_t txPin) : _bluetooth(rxPin, txPin) {
}

void BluetoothManager::init() {
    _bluetooth.begin(9600);
    _bluetooth.println("AT+VERSION");
    delay(100);
    while (_bluetooth.available()) {
        Serial.write(_bluetooth.read());
    }
}

void BluetoothManager::update() {
    if (_bluetooth.available()) {
        char c = _bluetooth.read();
        Serial.write(c);
    }
}

bool BluetoothManager::connectBluetooth() {
    _bluetooth.println("AT+ROLE=1"); // Set the device as a slave
    delay(100);
    _bluetooth.println("AT+NAMEMyBluetoothDevice");
    delay(100);
    _bluetooth.println("AT+PSWD1234");
    delay(100);
    _bluetooth.println("AT+INIT");
    delay(1000);
    _bluetooth.println("AT+INQ");
    delay(1000);

    String response;
    while (_bluetooth.available()) {
        char c = _bluetooth.read();
        response += c;
    }
    if (response.indexOf("OK") >= 0) {
        _isConnected = true;
        return true;
    }
    return false;
}

void BluetoothManager::requestWarrantyInfo() {
    if (!_isConnected) {
        Serial.println("Bluetooth is not connected.");
        return;
    }

    _bluetooth.println("Requesting warranty info...");
    delay(100);
    // Here you would send a specific command to request warranty info
    // This is just a placeholder command
    _bluetooth.println("AT+WARINFO");
    delay(1000);
    
    // Read the response
    while (_bluetooth.available()) {
        Serial.write(_bluetooth.read());
    }
}