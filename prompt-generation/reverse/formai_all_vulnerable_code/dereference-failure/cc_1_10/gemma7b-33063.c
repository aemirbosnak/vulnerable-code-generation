//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, buckets[n], min, max;
    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    buckets[0] = (max - min) / n + 1;
    for (k = 1; k < n; k++)
        buckets[k] = buckets[k - 1] * 2;

    int **buckets_arr = (int **)malloc(buckets[n] * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets_arr[i] = (int *)malloc(buckets[n] * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            buckets_arr[i][j] = arr[i][j];
        }
    }

    bucket_sort(buckets_arr, buckets[n]);

    for (i = 0; i < n; i++)
    {
        free(buckets_arr[i]);
    }
    free(buckets_arr);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", buckets_arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (int *)malloc(10 * sizeof(int));
    }

    arr[0][0] = 5;
    arr[0][1] = 3;
    arr[0][2] = 8;
    arr[0][3] = 2;
    arr[0][4] = 4;
    arr[0][5] = 7;
    arr[0][6] = 6;
    arr[0][7] = 1;
    arr[0][8] = 9;
    arr[0][9] = 3;

    bucket_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}