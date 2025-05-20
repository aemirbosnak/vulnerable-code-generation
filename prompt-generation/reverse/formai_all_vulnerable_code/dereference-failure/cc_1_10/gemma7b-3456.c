//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n)
{
    int i, j, k, min, max, range, bucketSize, **buckets;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];

            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    range = max - min + 1;
    bucketSize = range / n;

    buckets = (int *)malloc(n * bucketSize * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        buckets[k] = buckets[k] + 1;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[j][0] = min + i;
        }
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
    arr[1][1] = 8;
    arr[2][0] = 3;
    arr[2][1] = 7;
    arr[3][0] = 4;
    arr[3][1] = 6;

    bucketSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}