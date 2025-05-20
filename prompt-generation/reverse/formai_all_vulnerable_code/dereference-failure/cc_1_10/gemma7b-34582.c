//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize = MAX;
    int *buckets = (int *)malloc(bucketSize * sizeof(int));
    for (i = 0; i < n; i++)
    {
        buckets[*arr[i]]++;
    }
    for (j = 0; j < bucketSize; j++)
    {
        for (k = 0; buckets[j] > 0; k++)
        {
            arr[k] = j;
            buckets[j]--;
        }
    }
    free(buckets);
}

int main()
{
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Generate some random numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = rand() % MAX;
        }
    }

    bucketSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}