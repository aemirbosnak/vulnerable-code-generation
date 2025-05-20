//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main()
{
    int i, j, k, l, n, m;
    double time_taken, start_time, end_time, average_time;

    // Allocate memory for a large array
    int *arr = (int *)malloc(100000 * sizeof(int));

    // Initialize the array with random numbers
    for (i = 0; i < 100000; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Start the timer
    start_time = clock();

    // Perform a series of nested loops
    for (k = 0; k < MAX_ITERATIONS; k++)
    {
        for (l = 0; l < 1000; l++)
        {
            for (m = 0; m < 500; m++)
            {
                n = arr[m] + l;
            }
        }
    }

    // Stop the timer
    end_time = clock();

    // Calculate the time taken
    time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the average time taken per iteration
    average_time = time_taken / MAX_ITERATIONS;

    // Print the results
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Average time taken per iteration: %.2f milliseconds\n", average_time * 1000);

    // Free the memory
    free(arr);

    return 0;
}