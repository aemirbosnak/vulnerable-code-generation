//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int i, j;
    double sum;
    clock_t start, end;

    // Allocate memory for arrays
    int *a = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *b = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *c = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // Initialize arrays
    for (i = 0; i < ARRAY_SIZE; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    // Start the timer
    start = clock();

    // Perform the element-wise multiplication
    for (i = 0; i < ARRAY_SIZE; i++) {
        c[i] = a[i] * b[i];
    }

    // Stop the timer
    end = clock();

    // Calculate the elapsed time
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the sum of the elements in array c
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += c[i];
    }

    // Print the results
    printf("Element-wise multiplication of two arrays of size %d took %f seconds.\n", ARRAY_SIZE, time_elapsed);
    printf("The sum of the elements in the result array is %f.\n", sum);

    // Free the allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}