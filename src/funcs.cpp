#include <funcs.h>
#include <WiFi.h>

bool connect_to_AP(String ssid, String passwd){
    WiFi.begin(ssid.c_str(), passwd.c_str());

    int timeout_counter = 0;

    while (WiFi.status() != WL_CONNECTED && timeout_counter < 20){
        timeout_counter++;

        Serial.print('.');

        delay(500);
    }

    Serial.println();

    if (WiFi.status() == WL_CONNECTED){
        return true;
    }
    else {
        return false;
    }
}

bool host_AP(String AP_SSID, String AP_PASSWD){
    if (WiFi.softAP(AP_SSID.c_str(), AP_PASSWD.c_str())){
        return true;
    }
    else {
        return false;
    }
}