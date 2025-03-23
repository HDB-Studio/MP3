#include "ScreenManager.h"
#include "SDCardManager.h"
#include "BluetoothManager.h"
#include "InputManager.h"

ScreenManager screenManager;
SDCardManager sdCardManager;
BluetoothManager bluetoothManager(2, 3); // 定义 RX 和 TX 引脚
InputManager inputManager;

void setup() {
  Serial.begin(9600);
  screenManager.init();
  sdCardManager.init();
  bluetoothManager.init();
  if (bluetoothManager.connectBluetooth()) {
    Serial.println("Bluetooth connected successfully.");
  } else {
    Serial.println("Failed to connect Bluetooth.");
  }
  inputManager.init();
}

void loop() {
  inputManager.readInput();
  bluetoothManager.update();
  screenManager.updateDisplay();
  
  // Example: Request warranty info every 5 seconds
  static unsigned long lastRequestTime = 0;
  if (millis() - lastRequestTime > 5000) {
    lastRequestTime = millis();
    bluetoothManager.requestWarrantyInfo();
  }
}