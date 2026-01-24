#include <stdio.h>
#include "pico/stdlib.h"

void quicksort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
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

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main() {
    stdio_init_all();
    sleep_ms(15000);

    int data[] = {9, 2, 7, 12, 5, 10, 3, 1, 8, 6};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    quicksort(data, 0, size - 1);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    while (1) {
        sleep_ms(2500); // Keep the USB serial active
    }

    return 0;
}
