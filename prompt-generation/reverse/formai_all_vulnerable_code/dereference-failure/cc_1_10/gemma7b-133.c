//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **arr, int *size)
{
    int i, j, count = 0, prev = -1, flag = 0;
    char **ptr = NULL;

    *size = 0;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (arr[i] != prev)
        {
            prev = arr[i];
            count++;
            if (count > 1)
            {
                *size += count - 1;
                ptr = realloc(*arr, (*size) * sizeof(char));
                arr = ptr;
            }
            flag = 1;
        }
    }

    if (flag)
    {
        *size = count;
    }
}

int main()
{
    char **arr = NULL;
    int size = 0, i;

    arr = malloc(MAX_SIZE * sizeof(char));

    // Sample data
    arr[0] = 'a';
    arr[1] = 'a';
    arr[2] = 'b';
    arr[3] = 'b';
    arr[4] = 'c';
    arr[5] = 'c';
    arr[6] = 'c';

    compress(arr, &size);

    printf("Original size: %d\n", size);
    printf("Compressed size: %d\n", size);

    free(arr);

    return 0;
}