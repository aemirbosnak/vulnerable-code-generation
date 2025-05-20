//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, *bucket, **sorted_arr;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / MAX_SIZE + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    sorted_arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < bucket_size; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
    {
        bucket[arr[i][0]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            sorted_arr[j] = arr[i][0];
        }
    }

    free(bucket);
    free(sorted_arr);
}

int main()
{
    int **arr = (int **)malloc(10 * sizeof(int *));
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 3;
    arr[0][1] = 5;
    arr[1][0] = 2;
    arr[1][1] = 4;
    arr[2][0] = 4;
    arr[2][1] = 6;
    arr[3][0] = 6;
    arr[3][1] = 8;
    arr[4][0] = 5;
    arr[4][1] = 9;
    arr[5][0] = 8;
    arr[5][1] = 10;
    arr[6][0] = 2;
    arr[6][1] = 3;
    arr[7][0] = 4;
    arr[7][1] = 5;
    arr[8][0] = 6;
    arr[8][1] = 7;
    arr[9][0] = 8;
    arr[9][1] = 9;

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    printf("\n");

    free(arr);

    return 0;
}