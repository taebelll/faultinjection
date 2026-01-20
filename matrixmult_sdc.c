#include <stdio.h>
#include "pico/stdlib.h"

#define R1 2
#define C1 2
#define R2 2
#define C2 3

void multiplyMatrix(int m1[][C1], int m2[][C2]) {
    int result[R1][C2];
    printf("Resultant Matrix (SDC injected):\n");

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            volatile int acc = 0;

            // --- SDC: flip one bit in a register used for computation ---
            acc ^= (1 << 1);

            for (int k = 0; k < R2; k++) {
                acc += m1[i][k] * m2[k][j];
            }
            result[i][j] = acc;
            printf("%d\t", result[i][j]);
        }
        printf("\n");
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
