//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main(int argc, char *argv[]) {
    int *arr;
    int i, j, k, n;
    clock_t start, end;

    // Allocate memory for the array
    arr = (int *)malloc(SIZE * sizeof(int));

    // Initialize the array with random values
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using selection sort
    for (i = 0; i < SIZE - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx!= i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    // Measure the time taken to sort the array
    start = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (arr[i] == arr[j]) {
                k++;
            }
        }
    }
    end = clock();
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}