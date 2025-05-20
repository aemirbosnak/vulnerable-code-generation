//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROUNDS 1000000
#define ARRAY_SIZE 1000000

int main() {

    int i, j;
    int *arr;
    double elapsed_time;

    // Allocate memory for the array
    arr = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // Initialize the array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array
    for (i = 0; i < NUM_ROUNDS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Free the memory allocated for the array
    free(arr);

    // Measure the elapsed time
    clock_t start_time = clock();
    for (i = 0; i < NUM_ROUNDS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    clock_t end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}