//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, **bucket;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }

    bucket_size = (max - min) / 10 + 1;
    bucket = (int **)malloc(n * bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        bucket[arr[i][0]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[k][0] = i + min;
            k++;
        }
    }

    free(bucket);
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
    arr[5][0] = 6;
    arr[5][1] = 13;

    bucket_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("(%d, %d)\n", arr[i][0], arr[i][1]);
    }

    return 0;
}