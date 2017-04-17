#!/bin/bash
for f in src/gfx/*.png; do
    convert $f -format xbm ${f%.png}.xbm;
    sed 's/static char/static const char PROGMEM/' -i ${f%.png}.xbm;
done
