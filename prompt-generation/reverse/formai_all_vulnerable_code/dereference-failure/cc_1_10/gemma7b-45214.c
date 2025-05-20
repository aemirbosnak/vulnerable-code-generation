//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

void bucket_sort(char **arr, int n)
{
    int i, j, k, bucket_size = MAX_SIZE;
    char **buckets = (char **)malloc(bucket_size * sizeof(char *));
    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (char *)malloc(n * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - 'a';
        buckets[k][i] = arr[i];
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; buckets[i][j] != NULL; j++)
        {
            printf("%s ", buckets[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < bucket_size; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    char **arr = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    arr[0] = "abc";
    arr[1] = "bcd";
    arr[2] = "ace";
    arr[3] = "bca";

    bucket_sort(arr, 4);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}