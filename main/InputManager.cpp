#include "InputManager.h"
#include <Arduino.h>

#define BUTTON_UP A0
#define BUTTON_DOWN A1
#define BUTTON_ENTER A2
#define VOLUME_POT A3

void InputManager::init() {
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_ENTER, INPUT_PULLUP);
    pinMode(VOLUME_POT, INPUT);
}

void InputManager::readInput() {
    int buttonUpState = digitalRead(BUTTON_UP);
    int buttonDownState = digitalRead(BUTTON_DOWN);
    int buttonEnterState = digitalRead(BUTTON_ENTER);
    int volumeValue = analogRead(VOLUME_POT);

    if (buttonUpState == LOW) {
        Serial.println("上键按下");
    }
    if (buttonDownState == LOW) {
        Serial.println("下键按下");
    }
    if (buttonEnterState == LOW) {
        Serial.println("确认键按下");
    }
    Serial.print("音量值：");
    Serial.println(volumeValue);
}