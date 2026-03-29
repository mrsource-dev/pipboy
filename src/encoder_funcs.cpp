#include <ESP32Encoder.h>
#include <Arduino.h>
#include <globals.h>
#include <encoder_funcs.h>

char read_enc(){
    long current_steps = (long)encoder.getCount();   

    if (current_steps < last_step){
        Serial.println('d');

        last_step = current_steps;
        return 'd';
    }
    else if (current_steps > last_step){
        Serial.println('u');

        last_step = current_steps;
        return 'u';
    }

    Serial.println("n");

    last_step = current_steps;
    return 'n';
}