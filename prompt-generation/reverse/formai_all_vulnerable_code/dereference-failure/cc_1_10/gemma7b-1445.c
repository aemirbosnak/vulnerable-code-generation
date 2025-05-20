//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void compress(char **arr, int size)
{
    int i, j, count = 1, flag = 0;
    char **compressed = NULL;

    compressed = malloc(sizeof(char *) * size);
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size && arr[i] == arr[j]; j++)
        {
            count++;
        }
        compressed[flag++] = arr[i];
        compressed[flag++] = count;
        count = 1;
    }

    free(arr);
    arr = compressed;
}

int main()
{
    char **arr = NULL;
    int size = 10;

    arr = malloc(sizeof(char *) * size);
    arr[0] = 'a';
    arr[1] = 'a';
    arr[2] = 'b';
    arr[3] = 'b';
    arr[4] = 'b';
    arr[5] = 'c';
    arr[6] = 'c';
    arr[7] = 'c';
    arr[8] = 'c';
    arr[9] = 'a';

    compress(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}