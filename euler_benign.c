#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"

static inline double flip_bit(double x) {
    union {
        double d;
        uint64_t u;
    } reg;

    reg.d = x;
    reg.u ^= (1ULL << 18);  // mantissa bit flip
    return reg.d;
}

double compute_euler(int steps) {
    double e = 1.0;
    double term = 1.0;

    for (int i = 1; i <= steps; i++) {

        term *= 1.0 / i;

        // ---- BENIGN FAULT ----
        if (i == 5) {
            term = flip_bit(term);  // corrupted
        }
        // ---------------------

        // term is recomputed next iteration → fault masked
        e += term;
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
