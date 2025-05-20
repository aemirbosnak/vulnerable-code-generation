//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, min, max, buckets[n], *temp = NULL;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    buckets[0] = (max - min) / n + 1;
    for (i = 1; i < n; i++)
    {
        buckets[i] = buckets[i - 1] + 1;
    }

    temp = (int *)malloc(buckets[n] * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)realloc(arr[i], buckets[i] * sizeof(int));
        for (j = buckets[i - 1]; j < buckets[i]; j++)
        {
            arr[i][j] = temp[j];
        }
    }

    free(temp);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    bucket_sort(arr, n);

    printf("Sorted elements:");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d ", arr[i][0], arr[i][1]);
    }

    return 0;
}