#include <stdio.h>
#include "pico/stdlib.h"

#define R1 2
#define C1 2
#define R2 2
#define C2 3

void multiplyMatrix(int m1[][C1], int m2[][C2]) {
    printf("Resultant Matrix (hang injected):\n");

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            volatile int run = 0;

            // --- Hang: flip one bit to force infinite loop ---
            run ^= 1;
            while (run) {
                tight_loop_contents();
            }
        }
    }
}

int main() {
    stdio_init_all();
    sleep_ms(30000);

    int m1[R1][C1] = {{1,1},{2,2}};
    int m2[R2][C2] = {{1,1,1},{2,2,2}};

    multiplyMatrix(m1, m2);
    while (1) sleep_ms(1000);
}
