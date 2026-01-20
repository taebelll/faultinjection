#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"

double compute_euler(int steps) {
    double e = 1.0;
    double term = 1.0;

    for (int i = 1; i <= steps; i++) {
        term *= 1.0 / i;
        e += term;

        // ---- CRASH FAULT ----
        if (i == 6) {
            volatile uint32_t *bad_ptr = (uint32_t *)0x00000000;
            *bad_ptr = 0xDEADBEEF;  // HardFault
        }
        // --------------------
    }

    return e;
}

int main() {
    stdio_init_all();
    sleep_ms(15000);

    printf("Euler's constant e ≈ %18.16f (after 16 terms)\n",
           compute_euler(16));

    while (1) sleep_ms(2500);
}

