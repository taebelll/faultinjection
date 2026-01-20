#include <stdio.h>
#include "pico/stdlib.h"

void inject_benign_register_fault(void) {
    volatile uint32_t reg = 0x0;   // forces register allocation
    reg ^= (1u << 0);              // flip 1 bit (benign)
    (void)reg;                     // prevent optimization
}

void quicksort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    // --- Benign fault injection ---
    inject_benign_register_fault();

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main() {
    stdio_init_all();

    // Allow time for USB serial to enumerate
    sleep_ms(15000);

    int data[] = {9, 2, 7, 12, 5, 10, 3, 1, 8, 6};
    int size = sizeof(data) / sizeof(data[0]);

    // --- BEFORE sorting ---
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Sorting with benign fault injected
    quicksort(data, 0, size - 1);

    // --- AFTER sorting ---
    printf("After sorting (benign fault injected):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Keep USB serial alive
    while (1) {
        sleep_ms(1000);
    }
}
