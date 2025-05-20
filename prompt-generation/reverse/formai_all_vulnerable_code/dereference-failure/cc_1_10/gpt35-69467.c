//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n)
{
    // Create buckets for each possible integer value
    int* bucket = malloc(sizeof(int) * n);
    int i, j;

    for (i = 0; i < n; i++)
    {
        bucket[i] = 0;
    }

    // Increment the appropriate bucket count for each integer in the array
    for (i = 0; i < n; i++)
    {
        bucket[array[i]]++;
    }

    // Sort the array by iterating through the buckets in order and
    // inserting each integer the appropriate number of times into the sorted array
    for (i = 0, j = 0; i < n; i++)
    {
        while ((bucket[i]--) > 0)
        {
            array[j++] = i;
        }
    }

    free(bucket);
}

// Driver code
int main()
{
    int array[] = {3, 6, 1, 0, 2, 5, 4};
    int n = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Before sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    bucketSort(array, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}