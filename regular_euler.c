#include <stdio.h>
#include "pico/stdlib.h"

double compute_euler(int steps) {
    double e = 1.0;
    double term = 1.0;

    for (int i = 1; i <= steps; i++) {
        term *= 1.0 / i;
        e += term;
    }

    return e;
}

int main() {
    stdio_init_all();
    sleep_ms(15000);  // Wait for USB serial to connect

    int steps = 16;
    double result = compute_euler(steps);
    printf("Euler's constant e ≈ %18.16f (after %d terms)\n", result, steps);

    while (1) {
        sleep_ms(2500); // Keep the USB alive
    }

    return 0;
}
