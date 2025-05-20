//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n;
    int *array;
    clock_t start, end;

    // Allocate memory for array
    array = (int *) malloc(MAX_SIZE * sizeof(int));

    // Initialize array with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Prompt user for number of runs
    printf("Enter the number of runs: ");
    scanf("%d", &n);

    // Benchmarking loop
    for (j = 0; j < n; j++) {
        // Start timer
        start = clock();

        // Bubble sort algorithm
        for (i = 0; i < MAX_SIZE - 1; i++) {
            for (int k = 0; k < MAX_SIZE - i - 1; k++) {
                if (array[k] > array[k + 1]) {
                    int temp = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = temp;
                }
            }
        }

        // Stop timer
        end = clock();

        // Print execution time
        double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Execution time for run %d: %.6f seconds\n", j + 1, elapsed_time);
    }

    // Free memory
    free(array);

    return 0;
}