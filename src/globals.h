#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
// #include <TFT_eSPI.h>
#include <vector>
#include <ESP32Encoder.h>
#include "LGFX_ILI9488.hpp"

extern LGFX lcd;
extern ESP32Encoder encoder;

// menu
extern String current_tab;
extern int selected;
extern std::vector<String> menu_tabs;

// encoder
extern long last_step;

#endif