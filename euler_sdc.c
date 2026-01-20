#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"

static inline double flip_register_bit(double x, uint8_t bit) {
    union {
        double d;
        uint64_t u;
    } reg;

    reg.d = x;              // correct value in register
    reg.u ^= (1ULL << bit); // REGISTER BIT-FLIP
    return reg.d;
}

double compute_euler(int steps) {
    double e = 1.0;
    double term = 1.0;

    for (int i = 1; i <= steps; i++) {
        term *= 1.0 / i;

        // ---- SDC: REGISTER BIT-FLIP ----
        if (i == 6) {
            term = flip_register_bit(term, 52); // exponent LSB
        }
        // --------------------------------

        e += term;
    }

    return e;
}

int main() {
    stdio_init_all();
    sleep_ms(15000);

    int steps = 16;
    double result = compute_euler(steps);
    printf("Euler's constant e ≈ %18.16f (after %d terms)\n", result, steps);

    while (1) {
        sleep_ms(2500);
    }

    return 0;
}
