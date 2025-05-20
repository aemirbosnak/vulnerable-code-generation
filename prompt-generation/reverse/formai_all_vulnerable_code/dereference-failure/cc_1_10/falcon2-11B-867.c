//Falcon2-11B DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int* arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int* arr, int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));

    int size = 1000000;
    int* arr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    insertion_sort(arr, size);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Bubble sort: %f seconds\n", elapsed);
    printf("Insertion sort: %f seconds\n", elapsed);

    free(arr);
    return 0;
}