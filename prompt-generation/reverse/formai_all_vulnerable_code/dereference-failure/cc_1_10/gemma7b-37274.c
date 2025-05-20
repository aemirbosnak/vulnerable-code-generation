//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, **buckets = NULL;

    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        buckets[k][i] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; buckets[i][j] != NULL; j++)
        {
            arr[j] = buckets[i][j];
        }
    }

    free(buckets);
}

int main()
{
    int n, i, arr[MAX], **arr_ptr = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr_ptr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr_ptr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr_ptr[i][0]);
    }

    bucket_sort(arr_ptr, n);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr_ptr[i][0]);
    }

    free(arr_ptr);

    return 0;
}