//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main()
{
    int i, n, size = MAX_SIZE, time_taken = 0;
    double avg_time = 0.0;

    // Allocate memory for an array
    int *arr = (int *)malloc(size * sizeof(int));

    // Fill the array with random numbers
    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Start the timer
    clock_t start = clock();

    // Calculate the sum of the array elements
    for (n = 0; n < size; n++)
    {
        int sum = 0;
        for (i = 0; i < size; i++)
        {
            sum += arr[i];
        }
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    time_taken = end - start;

    // Calculate the average time taken
    avg_time = (double)time_taken / size;

    // Print the results
    printf("Time taken: %d milliseconds\n", time_taken);
    printf("Average time taken: %.2f milliseconds\n", avg_time);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}