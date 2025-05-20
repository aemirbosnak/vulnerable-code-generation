//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, min, max, bucket_size;

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

    int **buckets = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            buckets[i][arr[i][j] - min] = arr[i][j];
        }
    }

    int **sorted_arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        sorted_arr[i] = (int *)malloc(arr[i][1] * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            sorted_arr[i][j] = buckets[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        free(buckets[i]);
    }

    free(buckets);

    for (i = 0; i < n; i++)
    {
        free(sorted_arr[i]);
    }

    free(sorted_arr);

    return;
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 2;

    arr[1][0] = 20;
    arr[1][1] = 3;

    arr[2][0] = 30;
    arr[2][1] = 4;

    arr[3][0] = 40;
    arr[3][1] = 5;

    arr[4][0] = 50;
    arr[4][1] = 6;

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i][1]; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}