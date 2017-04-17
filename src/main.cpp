#include "Arduino.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#include "SSD1306.h"

#include "gfx/fedora.xbm"

#define ADDRESS 0x3C

SSD1306  display(ADDRESS, -1, -1);

void setup()
{
    Serial.begin(9600);
    Serial.println();
    Serial.println();
    Serial.println("begin");
    delay(200);
    pinMode(LED_BUILTIN, OUTPUT);
    
    
    display.init();
    display.flipScreenVertically();
    
    display.clear();

    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Fedorator");

    
    display.drawXbm(64, 0, fedora_width, fedora_height, fedora_bits);
    display.display();
    
}

void loop() {
    /*
    Serial.println("loop");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);

    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    
    //display.clear();
    display.setColor(BLACK);
    display.fillRect(0, 32, 32, 64);
    display.setColor(WHITE);
    display.drawString(0, 32, String(millis()));
    display.display();
    */
}
