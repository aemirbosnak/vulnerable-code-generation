//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void bucket_sort(char **arr, int n)
{
    int i, j, k, bucket_size, min, max;
    char **buckets;

    min = arr[0][0];
    max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / MAX + 1;

    buckets = (char **)malloc(bucket_size * sizeof(char *));

    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (char *)malloc(n * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        buckets[k][i] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (buckets[i][j] != NULL)
            {
                printf("%s ", buckets[i][j]);
            }
        }
    }

    for (i = 0; i < bucket_size; i++)
    {
        free(buckets[i]);
    }

    free(buckets);
}

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));

    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    arr[0] = "John";
    arr[1] = "Peter";
    arr[2] = "Mary";
    arr[3] = "Bob";
    arr[4] = "Alice";

    bucket_sort(arr, MAX);

    for (int i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}