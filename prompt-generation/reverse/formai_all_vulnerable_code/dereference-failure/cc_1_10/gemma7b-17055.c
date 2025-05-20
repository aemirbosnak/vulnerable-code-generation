//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

void bucket_sort(char ***arr, int n)
{
    int i, j, k, bucket_size, index;
    char **bucket = (char **)malloc(n * MAX_SIZE);
    for (i = 0; i < n; i++)
    {
        bucket[i] = (char *)malloc(MAX_SIZE);
    }

    for (i = 0; i < n; i++)
    {
        index = arr[i][0] - 'a';
        bucket[index][0] = arr[i][0];
        bucket[index][1] = arr[i][1];
    }

    for (i = 0; i < n; i++)
    {
        arr[i][0] = bucket[i][0];
        arr[i][1] = bucket[i][1];
    }

    free(bucket);
}

int main()
{
    char ***arr = (char ***)malloc(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (char **)malloc(MAX_SIZE);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = (char *)malloc(MAX_SIZE);
        }
    }

    arr[0][0] = "a";
    arr[0][1] = "John";
    arr[1][0] = "b";
    arr[1][1] = "Jane";
    arr[2][0] = "c";
    arr[2][1] = "Jack";

    bucket_sort(arr, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}