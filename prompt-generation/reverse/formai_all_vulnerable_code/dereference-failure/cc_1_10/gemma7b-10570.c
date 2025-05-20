//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int *size)
{
    int i, j, k, count = 0, flag = 0;
    char **ptr = (char **)malloc(sizeof(char *) * MAX);

    for (i = 0; i < *size; i++)
    {
        count = 1;
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
    }

    *size = k;
    free(arr);
    arr = ptr;
}

int main()
{
    char **arr = (char **)malloc(sizeof(char *) * MAX);
    int size = 10;

    arr[0] = 'a';
    arr[1] = 'a';
    arr[2] = 'b';
    arr[3] = 'a';
    arr[4] = 'a';
    arr[5] = 'c';
    arr[6] = 'c';
    arr[7] = 'c';
    arr[8] = 'a';
    arr[9] = 'a';

    compress(arr, &size);

    printf("Compressed size: %d\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    return 0;
}