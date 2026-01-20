#include <stdio.h>
#include "pico/stdlib.h"

void quicksort(int *arr, int left, int right) {
    // --- Crash fault ---
    volatile int *bad_ptr = (int *)0xFFFFFFFF;
    *bad_ptr = 42;   // illegal write → crash
}

int main() {
    stdio_init_all();
    sleep_ms(15000);

    int data[] = {9, 2, 7, 12, 5, 10, 3, 1, 8, 6};

    printf("About to crash...\n");

    quicksort(data, 0, 9);

    while (1) {
        sleep_ms(2500);
    }
}
