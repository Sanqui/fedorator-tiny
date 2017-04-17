#include "main.h"

void main() {
    set_bit(LED_DDR, LED);

    while (1) {
        set_bit(LED_PORT, LED);
        _delay_ms(200);

        clear_bit(LED_PORT, LED);
        _delay_ms(300);
    }
}
