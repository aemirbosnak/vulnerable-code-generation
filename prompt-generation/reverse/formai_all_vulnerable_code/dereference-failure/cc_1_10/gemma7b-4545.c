//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

void compress(char **arr, int n)
{
    int i, j, count = 0, unique = 0, prev = -1;
    char **ptr = NULL;

    ptr = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        int current = arr[i];

        if (prev == current)
        {
            count++;
        }
        else
        {
            unique++;

            if (prev != -1)
            {
                ptr[unique - 1] = count;
            }

            prev = current;
            count = 1;
        }
    }

    free(arr);

    arr = (char **)ptr;

    printf("Number of unique characters: %d\n", unique);

    printf("Number of characters compressed: %d\n", unique - count);
}

int main()
{
    char *arr[] = {"abccaaabbbb", "xyz", "hello world"};
    int n = 3;

    compress(arr, n);

    return 0;
}