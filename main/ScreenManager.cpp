#include "ScreenManager.h"
#include <Adafruit_GFX.h>  // 确保包含这一行
#include <Adafruit_TFTLCD.h>
#include <Arduino.h>

#define LCD_CS 10
#define LCD_CD 9
#define LCD_WR 8
#define LCD_RD 7
#define LCD_RESET 6

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void ScreenManager::init() {
    tft.begin(0x9341);
    tft.setRotation(1);
    tft.fillScreen(Adafruit_GFX::BLACK);  // 使用 Adafruit_GFX::BLACK
}

void ScreenManager::updateDisplay() {
    // 更新屏幕显示
    tft.setCursor(0, 0);
    tft.setTextColor(Adafruit_GFX::WHITE);  // 使用 Adafruit_GFX::WHITE
    tft.setTextSize(1);
    tft.println("Hello, World!");
}