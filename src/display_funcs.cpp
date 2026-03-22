#include <TFT_eSPI.h>
#include <Arduino.h>
#include <globals.h>
#include <display_funcs.h>

#define PIPBOY_GREEN 0x1FE7

void draw_one_frame(){
    tft.setCursor(20, 20);

    tft.setTextSize(2);

    tft.setTextColor(PIPBOY_GREEN, TFT_BLACK);

    draw_menu();
}

void draw_menu(){
    for (int i = 0; i < menu_tabs.size(); i++){
        if (i == selected){
            Serial.println("Here");
            underline(tft.getCursorX(), tft.getCursorY(), menu_tabs[i], 2);
        }

        if (i < menu_tabs.size() - 1){
            tft.print(menu_tabs[i] + " | ");
        }
        else{
            tft.print(menu_tabs[i]);
        }
        Serial.println("not here");
    }
}

void underline(int x, int y, String word, int font_size){
    tft.setCursor(x, y);

    int width = tft.textWidth(word);

    tft.drawFastHLine(x, y + (8 * font_size), width, PIPBOY_GREEN);
}