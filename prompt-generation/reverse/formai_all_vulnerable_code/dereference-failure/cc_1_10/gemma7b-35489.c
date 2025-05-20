//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, **buckets, maxValue = arr[0][0];

    // Calculate the maximum value in the array to determine the bucket size
    for (i = 0; i < n; i++)
    {
        if (arr[i][0] > maxValue)
        {
            maxValue = arr[i][0];
        }
    }

    // Calculate the bucket size
    bucketSize = (maxValue / MAX) + 1;

    // Create buckets
    buckets = (int **)malloc(bucketSize * sizeof(int *));
    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++)
    {
        k = arr[i][0] / bucketSize;
        buckets[k][arr[i][0]] = arr[i];
    }

    // Merge the buckets
    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (buckets[i][j])
            {
                printf("%d ", buckets[i][j]);
            }
        }
    }

    // Free the buckets
    for (i = 0; i < bucketSize; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 5;
    arr[0][1] = 10;
    arr[1][0] = 2;
    arr[1][1] = 7;
    arr[2][0] = 8;
    arr[2][1] = 12;
    arr[3][0] = 3;
    arr[3][1] = 9;
    arr[4][0] = 4;
    arr[4][1] = 11;

    bucketSort(arr, 10);

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}