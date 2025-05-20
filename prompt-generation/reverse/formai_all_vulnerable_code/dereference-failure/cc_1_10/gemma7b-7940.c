//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, min, max, bucket_size, **buckets;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    bucket_size = (max - min) / n + 1;
    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            buckets[i][arr[i][j] - min] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bucket_size; j++)
        {
            if (buckets[i][j] == 1)
            {
                printf("(%d, %d) ", i, j + min);
            }
        }
    }

    free(buckets);
}

int main()
{
    int **arr = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
        arr[i] = (int *)malloc(2 * sizeof(int));

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;
    arr[2][0] = 5;
    arr[2][1] = 6;
    arr[3][0] = 7;
    arr[3][1] = 8;
    arr[4][0] = 9;
    arr[4][1] = 10;

    bucket_sort(arr, 5);

    free(arr);

    return 0;
}