//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucketSort(int arr[], int n)
{
    int i, j, k, bucketSize, *bucket, **histogram = NULL;

    histogram = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        histogram[i] = (int *)malloc(MAX * sizeof(int));
    }

    bucketSize = n / MAX;
    bucket = (int *)malloc(bucketSize * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucketSize;
        histogram[k][arr[i]]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (histogram[i][j] > 0)
            {
                bucket[i] += histogram[i][j] * j;
            }
        }
    }

    free(bucket);
    for (i = 0; i < n; i++)
    {
        free(histogram[i]);
    }
    free(histogram);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}