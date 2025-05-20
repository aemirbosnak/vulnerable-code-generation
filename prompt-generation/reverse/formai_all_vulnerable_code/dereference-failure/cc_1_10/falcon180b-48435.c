//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int *arr = (int *) malloc(sizeof(int) * SIZE);
    int i;

    // Initializing array elements
    for (i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    // Sorting array using bubble sort
    for (i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Calculating the time taken for sorting
    clock_t start_time = clock();
    for (i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    clock_t end_time = clock();
    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Printing the sorted array and time taken
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken for sorting: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}