#include <stdio.h>
#include "pico/stdlib.h"

#define R1 2
#define C1 2
#define R2 2
#define C2 3

static inline void inject_benign_register_fault(void) {
    volatile uint32_t dummy = 0;
    dummy ^= (1u << 0);   // flip one bit
    (void)dummy;         // ensure no optimization
}

void multiplyMatrix(int m1[][C1], int m2[][C2]) {
    int result[R1][C2];
    printf("Resultant Matrix (benign fault injected):\n");

    inject_benign_register_fault();  // benign

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
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
