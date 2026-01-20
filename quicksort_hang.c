#include <stdio.h>
#include "pico/stdlib.h"

void quicksort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    // --- Hang fault ---
    while (1) {
        tight_loop_contents();  // CPU stuck here
    }

    int temp;

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
}

int main() {
    stdio_init_all();
    sleep_ms(15000);

    int data[] = {9, 2, 7, 12, 5, 10, 3, 1, 8, 6};

    printf("Starting quicksort (hang injected)...\n");

    quicksort(data, 0, 9);

    while (1) {
        sleep_ms(2500);
    }
}
