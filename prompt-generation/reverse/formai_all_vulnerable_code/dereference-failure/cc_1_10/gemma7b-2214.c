//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            if (min > arr[i][2])
                min = arr[i][2];

            if (max < arr[i][2])
                max = arr[i][2];
        }
    }

    bucket_size = (max - min) / n + 1;

    int *bucket = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            bucket[arr[i][2]]++;
        }
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[k][0] = min + i;
            k++;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = (int **)malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 2;

    arr[1][0] = 15;
    arr[1][1] = 3;

    arr[2][0] = 20;
    arr[2][1] = 4;

    arr[3][0] = 25;
    arr[3][1] = 5;

    arr[4][0] = 30;
    arr[4][1] = 6;

    bucket_sort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < arr[i][1]; j++)
        {
            printf("%d ", arr[i][0]);
        }

        printf("\n");
    }

    free(arr);

    return 0;
}