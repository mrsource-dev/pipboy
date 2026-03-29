// #include <TFT_eSPI.h>
#include <Arduino.h>
#include <globals.h>
#include "LGFX_ILI9488.hpp"
// #include <display_funcs.h>

#define PIPBOY_GREEN 0x1FE7

/*
void draw_one_frame(){
    tft.fillRect(0, 15, 480, 30, TFT_BLACK);

    tft.setCursor(20, 20);

    tft.setTextSize(2);

    tft.setTextColor(PIPBOY_GREEN, TFT_BLACK);

    Serial.println(selected);

    draw_menu();
}

void draw_menu(){
    tft.setCursor(20, 20);

    for (int i = 0; i < menu_tabs.size(); i++){
        if (i == selected){
            //Serial.println("Here");
            underline(tft.getCursorX(), tft.getCursorY(), menu_tabs[i], 2);
        }

        if (i < menu_tabs.size() - 1){
            tft.print(menu_tabs[i] + " | ");
        }
        else{
            tft.print(menu_tabs[i]);
        }
        //Serial.println("not here");
    }
}

void underline(int x, int y, String word, int font_size){
    tft.setCursor(x, y);

    int width = tft.textWidth(word);

    tft.drawFastHLine(x, y + (8 * font_size), width, PIPBOY_GREEN);
}
*/

void draw_one_frame(){
    LGFX_Sprite canvas(&lcd);

    canvas.createSprite(120, 120);

    canvas.fillScreen(TFT_BLACK);

    canvas.fillCircle(60, 60, 40, TFT_RED);

    canvas.pushSprite(10, 10);
}