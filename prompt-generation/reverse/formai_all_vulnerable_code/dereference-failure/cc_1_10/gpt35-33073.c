//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 1000000

int main()
{
    int *arr = malloc(sizeof(int) * SIZE);
    int i, j, min_idx, temp;

    struct timeval start, end;
    long seconds, microseconds;

    // Fill the array with random numbers
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }

    // Record the start time
    gettimeofday(&start, NULL);

    // Selection sort algorithm
    for (i = 0; i < SIZE - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    // Record the end time
    gettimeofday(&end, NULL);

    // Calculate the time taken
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    printf("Time taken: %ld seconds %ld microseconds\n", seconds, microseconds);

    // Display the sorted array
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}