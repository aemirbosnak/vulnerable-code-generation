//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(int a, int b)
{
    return a - b;
}

// Function to bucket sort an array
void bucketSort(int *arr, int n)
{
    int i, j, k, bucketSize, min, max;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    bucketSize = (max - min) / n + 1;
    int *buckets = (int *)malloc(bucketSize * sizeof(int));
    for (i = 0; i < bucketSize; i++)
        buckets[i] = 0;

    for (i = 0; i < n; i++)
    {
        buckets[arr[i] - min]++ ;
    }

    int index = 0;
    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[index++] = i + min;
        }
    }

    free(buckets);
}

int main()
{
    int arr[] = {4, 3, 8, 6, 2, 5, 1, 9, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);

    printf("\n");

    return 0;
}