//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int *size)
{
    int i, j, count = 1, k = 0, b = 0;
    char **ptr = NULL;

    ptr = (char**)malloc((*size) * sizeof(char *));

    for (i = 0; i < *size; i++)
    {
        for (j = i + 1; j < *size && arr[i] == arr[j]; j++)
        {
            count++;
        }

        if (count > 1)
        {
            ptr[k++] = arr[i];
            ptr[k++] = count - 1;
        }
        else
        {
            ptr[k++] = arr[i];
        }

        count = 1;
    }

    *size = k;
    *arr = ptr;
}

int main()
{
    char **arr = NULL;
    int size = 0, i, data[] = { 1, 2, 2, 3, 3, 3, 4, 5, 5, 5 };

    compress(arr, &size);

    for (i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    return 0;
}