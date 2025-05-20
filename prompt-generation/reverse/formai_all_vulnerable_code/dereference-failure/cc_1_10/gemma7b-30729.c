//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main()
{
    int i, j, n, m, size, **arr, time_taken;
    clock_t start, end;

    // Allocate memory for the array
    arr = (int *)malloc(MAX_SIZE * sizeof(int));

    // Generate random numbers for the array
    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Time the sorting algorithm
    start = clock();

    // Bubble sort algorithm
    for (n = 0; n < MAX_SIZE - 1; n++)
    {
        for (m = 0; m < MAX_SIZE - n - 1; m++)
        {
            if (arr[m] > arr[m + 1])
            {
                int temp = arr[m];
                arr[m] = arr[m + 1];
                arr[m + 1] = temp;
            }
        }
    }

    end = clock();

    // Calculate the time taken
    time_taken = (end - start) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Time taken: %d seconds\n", time_taken);

    // Free the allocated memory
    free(arr);

    return 0;
}