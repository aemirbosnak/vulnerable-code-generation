//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1000000
#define ARRAY_SIZE 1000000

int main() {
    int i, j;
    int *array;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for array
    array = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // Initialize array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Sort array using bubble sort
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Measure time taken for sorting
    start = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for sorting: %lf seconds\n", cpu_time_used);

    // Free memory allocated for array
    free(array);

    return 0;
}