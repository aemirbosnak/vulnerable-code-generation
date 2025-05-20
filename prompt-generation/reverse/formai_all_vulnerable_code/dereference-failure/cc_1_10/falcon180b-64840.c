//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

// Function to be benchmarked
void my_function(int *array) {
    int i, j, temp;
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, *array;
    clock_t start, end;

    // Allocate memory for the array
    array = (int *)malloc(SIZE * sizeof(int));

    // Initialize the array with random values
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Start the timer
    start = clock();

    // Call the function to be benchmarked
    my_function(array);

    // Stop the timer
    end = clock();

    // Calculate the elapsed time
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    // Free the memory allocated for the array
    free(array);

    return 0;
}