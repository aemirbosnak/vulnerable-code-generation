//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to measure the time taken by the code
double measure_execution_time(clock_t start, clock_t end) {
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return time_taken;
}

int main() {
    // array size
    int n = 10000;

    // allocate memory for array
    int* arr = (int*)malloc(n * sizeof(int));

    // fill array with random values between 0 and 1000
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
    }

    // initialize variables to store maximum and minimum values
    int max = 0;
    int min = 1000;

    // start measuring time
    clock_t start = clock();

    // loop through array to find maximum and minimum values
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // stop measuring time
    clock_t end = clock();

    // print results
    printf("Maximum value of array: %d\n", max);
    printf("Minimum value of array: %d\n", min);
    printf("Time taken to execute code: %f seconds\n", measure_execution_time(start, end));

    // free allocated memory
    free(arr);

    return 0;
}