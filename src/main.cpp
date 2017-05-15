#include "Arduino.h"

#include "SSD1306.h"

#include "USBHost_t36.h"
#include "massstorage.h"

#include "gfx/fedora.xbm"

#define DISPLAY_ADDRESS 0x3C
SSD1306  display(DISPLAY_ADDRESS, I2C_PINS_33_34);

USBHost usbhost;
MassStorageController ms(usbhost);


void setup()
{
    Serial.begin(9600);
    Serial.println();
    Serial.println();
    Serial.println("begin");
    delay(200);
    
    
    display.init();
    //display.flipScreenVertically();
    
    display.clear();

    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Fedorator");

    
    display.drawXbm(64, 0, fedora_width, fedora_height, fedora_bits);
    display.display();
    
    Serial.println("display done");
    
	usbhost.begin();
}

int cnt = 0;

void loop() {
    usbhost.Task();
    
    cnt += 1;
    if (cnt % 16 == 0) {
        display.setColor(BLACK);
        display.fillRect(0, 28, 64, 64);
        display.setColor(WHITE);
        if (ms.connected) {
            display.drawString(0, 28, "USB FLASH\nFOUND");
        } else {
            display.drawString(0, 28, "USB FLASH\nNOT FOUND");
        }
        //display.drawString(0, 64-12, millis());
        display.display();
    }

}
