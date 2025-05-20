//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_ITER 100

int main(int argc, char *argv[]) {
    int i, j, size = MAX_SIZE;
    int *array;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));

    // Allocate memory for the array
    array = (int *) malloc(size * sizeof(int));

    // Initialize the array with random values
    for (i = 0; i < size; i++) {
        array[i] = rand() % MAX_SIZE;
    }

    // Sort the array using bubble sort
    for (i = 0; i < MAX_ITER; i++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Measure the time taken to sort the array
    start = clock();
    for (i = 0; i < MAX_ITER; i++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort the array: %lf seconds\n", cpu_time_used);

    // Free the allocated memory
    free(array);

    return 0;
}