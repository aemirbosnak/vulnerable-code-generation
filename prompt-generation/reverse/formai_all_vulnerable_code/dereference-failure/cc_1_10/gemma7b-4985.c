//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, min, max, buckets[n], *ptr;

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

    buckets[0] = (max - min) / n + 1;

    for (k = 1; k <= buckets[0]; k++)
    {
        buckets[k] = buckets[k - 1] + 1;
    }

    ptr = (int *)malloc(buckets[0] * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            buckets[arr[i][j]]++;
        }
    }

    for (i = 0; i < buckets[0]; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[j][0] = i;
        }
    }

    free(ptr);
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(2 * sizeof(int));

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 50;
    arr[2][1] = 60;
    arr[3][0] = 70;
    arr[3][1] = 80;
    arr[4][0] = 90;
    arr[4][1] = 100;

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}