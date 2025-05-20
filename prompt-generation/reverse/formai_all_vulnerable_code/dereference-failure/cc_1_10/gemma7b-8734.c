//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(int a, int b)
{
    return a - b;
}

void bucketSort(int *arr, int n)
{
    int i, j, k, min, max, bucketSize, *bucket;

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
    bucket = (int *)malloc(bucketSize * sizeof(int));

    for (i = 0; i < n; i++)
    {
        bucket[arr[i] - min] = 1;
    }

    k = 0;
    for (i = min; i <= max; i++)
    {
        if (bucket[i - min] == 1)
        {
            arr[k] = i;
            k++;
        }
    }

    free(bucket);
}

int main()
{
    int arr[] = {4, 3, 8, 6, 2, 5, 1, 9, 7, 3};
    int n = 10;

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}