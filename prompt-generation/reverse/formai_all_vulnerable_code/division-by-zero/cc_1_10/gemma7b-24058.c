//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, *bucket, **sorted_arr = NULL;

    sorted_arr = malloc(n * sizeof(int *));
    bucket = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = malloc(sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i][0]);
    }

    bucket_size = MAX_SIZE / n;

    for (i = 0; i < n; i++)
    {
        bucket[arr[i][0]]++;
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (bucket[i] > 0)
        {
            for (j = 0; j < bucket[i]; j++)
            {
                sorted_arr[k++] = i;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", sorted_arr[i]);
    }

    free(bucket);
    free(sorted_arr);
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
}

int main()
{
    int n;
    scanf("Enter the number of elements: ", &n);

    int **arr = NULL;
    arr = malloc(n * sizeof(int *));

    bucket_sort(arr, n);

    return 0;
}