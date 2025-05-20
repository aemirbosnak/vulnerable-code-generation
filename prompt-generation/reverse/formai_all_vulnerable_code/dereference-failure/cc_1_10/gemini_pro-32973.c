//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define REPEAT_COUNT 100

typedef struct {
    int *array;
    int size;
} Array;

Array create_array(int size) {
    Array array;
    array.size = size;
    array.array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array.array[i] = rand();
    }
    return array;
}

void free_array(Array array) {
    free(array.array);
}

int sum_array(Array array) {
    int sum = 0;
    for (int i = 0; i < array.size; i++) {
        sum += array.array[i];
    }
    return sum;
}

int main() {
    // Create an array of random integers
    Array array = create_array(ARRAY_SIZE);

    // Benchmark the sum_array function
    clock_t start_time = clock();
    for (int i = 0; i < REPEAT_COUNT; i++) {
        sum_array(array);
    }
    clock_t end_time = clock();

    // Calculate the time taken to run the benchmark
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the results
    printf("Time taken to sum the array %d times: %f seconds\n", REPEAT_COUNT, time_taken);

    // Free the memory allocated for the array
    free_array(array);

    return 0;
}