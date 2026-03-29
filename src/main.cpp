#include <Arduino.h>
// #include <TFT_eSPI.h>
#include <globals.h>
#include <display_funcs.h>
#include <FS.h>
#include <LittleFS.h>
#include <ESP32Encoder.h>
#include <encoder_funcs.h>
#include <funcs.h>
#include "LGFX_ILI9488.hpp"

// TFT_eSPI tft = TFT_eSPI();
LGFX lcd;
String current_tab = "STATS";
std::vector<String> menu_tabs = {"STATS", "SHELL", "SYSTEM"};
int selected = 1;
int counter = 0;
ESP32Encoder encoder;
long last_step = 0;

char state_enc;

const String SSID = "";
const String PASSWD = "";

// for AP that esp32 will host
const String AP_SSID = "pipboy_ap";
const String AP_PASSWD = "pipboy12";

void setup(){
    Serial.begin(115200);

    /*
    tft.init();
    tft.setRotation(1);
    tft.invertDisplay(true); 
    tft.setTextColor(0x1FE7, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);
    */

    //draw_one_frame();

    lcd.init();
    lcd.setRotation(1);
    lcd.drawRect(0, 0, lcd.width(), lcd.height(), 0x0000);
    //lcd.setBrightness(200);

    if (!LittleFS.begin()) {
        Serial.println("LittleFS Mount Failed!");
        return;
    }

    pinMode(ENC_SW, INPUT_PULLUP);

    ESP32Encoder::useInternalWeakPullResistors = UP;
    encoder.attachFullQuad(ENC_CLK, ENC_DT);

    encoder.setCount(0);

    // Connecting to AP for internet connection
    bool res = connect_to_AP(SSID, PASSWD);

    if (res == false){
        Serial.println("Cant connect to AP");
    }

    IPAddress ip = WiFi.localIP();

    Serial.println("ESP's IP address: " + ip.toString());

    int counter = 0;
}

void loop(){
    lcd.drawRect(0, 0, lcd.width(), lcd.height(), TFT_BLACK);

    Serial.print("WIDTH: ");
    Serial.println(lcd.width());

    Serial.print("HEIGHT: ");
    Serial.println(lcd.height());

    state_enc = read_enc();

    if (state_enc != 'n'){
        //draw_one_frame();
    }

    if (counter == 5){
        selected++;

        if (selected == 3){
            selected = 0;
        }

        counter = 0;
    }

    counter++;

    //draw_one_frame();

    delay(200);
}