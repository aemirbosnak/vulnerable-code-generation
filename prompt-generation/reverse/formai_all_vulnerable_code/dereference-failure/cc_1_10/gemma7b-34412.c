//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;
    int *bucket = NULL;

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
    bucket = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            k = (arr[i][j] - min) / MAX;
            bucket[k]++;
        }
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[j][0] = min + i * MAX;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = NULL;
    int n;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(MAX * sizeof(int));

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
            printf("%d ", arr[i][j]);

        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}