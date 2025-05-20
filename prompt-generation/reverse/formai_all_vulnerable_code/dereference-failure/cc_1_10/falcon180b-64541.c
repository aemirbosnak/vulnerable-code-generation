//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j, k;
    int *arr1, *arr2;
    clock_t start, end;

    // Allocate memory for two arrays
    arr1 = (int *)malloc(SIZE * sizeof(int));
    arr2 = (int *)malloc(SIZE * sizeof(int));

    // Initialize the arrays with random values
    for (i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    // Start the timer
    start = clock();

    // Sort the first array using bubble sort
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                // Swap arr1[j] and arr1[j+1]
                k = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = k;
            }
        }
    }

    // End the timer
    end = clock();

    // Calculate the time taken for bubble sort
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort: %lf seconds\n", time_taken);

    // Free the memory allocated for the arrays
    free(arr1);
    free(arr2);

    return 0;
}