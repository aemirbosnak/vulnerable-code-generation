//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Generate two random arrays
    int *array1 = malloc(SIZE * sizeof(int));
    int *array2 = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        array1[i] = rand();
        array2[i] = rand();
    }

    // Record start time for first benchmark
    start = clock();

    // Perform benchmarking operation
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array1[i] + array2[i];
    }

    // Record end time for first benchmark
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Benchmark 1 Result: %d\n", sum);
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Record start time for second benchmark
    start = clock();

    // Perform benchmarking operation
    int product = 1;
    for (int i = 0; i < SIZE; i++) {
        product *= array1[i] * array2[i];
    }

    // Record end time for second benchmark
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Benchmark 2 Result: %d\n", product);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    // Free memory used by arrays
    free(array1);
    free(array2);

    return 0;
}