#include <Arduino.h>
#include <TFT_eSPI.h>
#include <globals.h>
#include <display_funcs.h>
#include <FS.h>
#include <LittleFS.h>
#include <ESP32Encoder.h>

TFT_eSPI tft = TFT_eSPI();
String current_tab = "STATS";
std::vector<String> menu_tabs = {"STATS", "SHELL", "SYSTEM"};
int selected = 0;
int counter = 0;
ESP32Encoder encoder;

void setup(){
    Serial.begin(115200);

    if (!LittleFS.begin()) {
        Serial.println("LittleFS Mount Failed!");
        return;
    }

    tft.init();
    tft.setRotation(1);
    tft.invertDisplay(true); 
    tft.setTextColor(0x1FE7, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);

    pinMode(ENC_SW, INPUT_PULLUP);

    ESP32Encoder::useInternalWeakPullResistors = UP;
    encoder.attachFullQuad(ENC_CLK, ENC_DT);
}

void loop(){
    draw_one_frame();

    counter++;

    Serial.println(counter);
}