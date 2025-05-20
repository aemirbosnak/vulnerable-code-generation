//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int **size)
{
    int i = 0, j = 0, count = 1, duplicate = 0;
    char **temp = NULL;

    *size = 0;

    for (i = 0; arr[i] != NULL; i++)
    {
        for (j = i + 1; arr[j] != NULL && arr[i] == arr[j]; j++)
        {
            duplicate++;
            count++;
        }

        if (duplicate > 0)
        {
            temp = realloc(*arr, MAX * (count + 1));
            *arr = temp;

            arr[i] = '#';
            arr[i + 1] = (char)duplicate;
            i++;
            duplicate = 0;
            count = 1;
        }

        *size = i + 1;
    }

    free(temp);
}

int main()
{
    char **arr = NULL;
    int size = 0;

    arr = malloc(MAX);
    arr[0] = 'a';
    arr[1] = 'a';
    arr[2] = 'b';
    arr[3] = 'b';
    arr[4] = 'c';
    arr[5] = NULL;

    compress(arr, &size);

    printf("Compressed size: %d\n", size);

    return 0;
}