#include "SDCardManager.h"
#include <SPI.h>
#include <SD.h>
#include <Arduino.h>

#define SD_CS 4

void SDCardManager::init() {
    if (!SD.begin(SD_CS)) {
        Serial.println("SD卡初始化失败！");
        while (1);
    }
    Serial.println("SD卡初始化成功！");
}

bool SDCardManager::readFile(const char* filename) {
    File file = SD.open(filename);
    if (!file) {
        Serial.print("无法打开文件：");
        Serial.println(filename);
        return false;
    }
    // 读取文件内容
    while (file.available()) {
        Serial.write(file.read());
    }
    file.close();
    return true;
}