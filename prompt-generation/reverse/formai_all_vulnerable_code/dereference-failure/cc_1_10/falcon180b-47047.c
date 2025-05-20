//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n;
    double start_time, end_time;
    int *array;

    // Allocate memory for array
    array = (int *) malloc(MAX_SIZE * sizeof(int));

    // Fill array with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Sort array using bubble sort
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Measure time taken to sort array
    start_time = clock();
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end_time = clock();

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print time taken to sort array
    n = (int) ((double) (end_time - start_time) / CLOCKS_PER_SEC);
    printf("Time taken to sort array: %d seconds\n", n);

    // Free memory allocated for array
    free(array);

    return 0;
}