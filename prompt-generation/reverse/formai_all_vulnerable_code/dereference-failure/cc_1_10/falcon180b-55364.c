//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j;
    int *array;
    double start_time, end_time;

    // Allocate memory for the array
    array = (int *) malloc(SIZE * sizeof(int));

    // Initialize the array
    for (i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    // Sort the array using bubble sort
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Measure the time taken to sort the array
    start_time = clock();
    for (i = 0; i < SIZE; i++) {
        if (array[i]!= i) {
            printf("Error: Array is not sorted correctly!\n");
            exit(1);
        }
    }
    end_time = clock();

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken to sort the array: %.6f seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    // Free the memory allocated for the array
    free(array);

    return 0;
}