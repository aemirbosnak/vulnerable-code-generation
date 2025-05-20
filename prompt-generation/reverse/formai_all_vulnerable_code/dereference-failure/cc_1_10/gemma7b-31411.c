//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, **bucket;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    bucket_size = (max - min) / MAX + 1;
    bucket = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
        bucket[i] = (int *)malloc(MAX * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            bucket[arr[i][j] - min][j] = arr[i][j];
        }
    }

    int **res = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        res[i] = (int *)malloc(MAX * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            res[i][j] = bucket[arr[i][j] - min][j];
        }
    }

    free(bucket);
    free(res);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
        arr[i] = (int *)malloc(MAX * sizeof(int));

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[0][4] = 50;

    arr[1][0] = 15;
    arr[1][1] = 25;
    arr[1][2] = 35;
    arr[1][3] = 45;
    arr[1][4] = 60;

    bucket_sort(arr, 2);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}