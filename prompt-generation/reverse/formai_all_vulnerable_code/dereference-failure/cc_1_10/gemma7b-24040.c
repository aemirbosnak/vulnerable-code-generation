//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, *bucket, **temp_arr;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        if (arr[i][0] < min)
            min = arr[i][0];
        if (arr[i][0] > max)
            max = arr[i][0];
    }

    bucket_size = (max - min) / n + 1;
    bucket = (int *)malloc(bucket_size * n * sizeof(int));
    temp_arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        temp_arr[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        temp_arr[k][i] = arr[i][1];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (temp_arr[i][j] != 0)
            {
                arr[j][1] = temp_arr[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        free(temp_arr[i]);
    }

    free(temp_arr);
    free(bucket);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    bucket_sort(arr, n);

    printf("Sorted elements:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i][1]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}