#include <stdio.h>
#include "pico/stdlib.h"

#define R1 2
#define C1 2
#define R2 2
#define C2 3

void multiplyMatrix(int m1[][C1], int m2[][C2]) {
    // --- Crash: register bit flip corrupts pointer ---
    volatile uint32_t reg = 0;
    reg ^= (1u << 31);          // flip one bit (MSB)
    volatile int *bad = (int *)reg;
    *bad = 42;                 // illegal write → crash
}

int main() {
    stdio_init_all();
    sleep_ms(30000);

    int m1[R1][C1] = {{1,1},{2,2}};
    int m2[R2][C2] = {{1,1,1},{2,2,2}};

    printf("About to crash...\n");
    multiplyMatrix(m1, m2);
    while (1) sleep_ms(1000);
}
