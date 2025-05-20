//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int compress(char **arr, int **size, int n)
{
    int i, count = 0, newSize = 0, prevChar = 0, prevCount = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == prevChar)
        {
            prevCount++;
        }
        else
        {
            if (prevCount)
            {
                *size += prevCount - 1;
                arr[newSize++] = prevChar;
                prevCount = 1;
            }
            prevChar = arr[i];
            prevCount = 1;
        }
    }

    if (prevCount)
    {
        *size += prevCount - 1;
        arr[newSize++] = prevChar;
    }

    *size = newSize;
    return 0;
}

int main()
{
    char *arr = "aabbbbca";
    int size = 0, n = 6;

    compress(&arr, &size, n);

    printf("Compressed array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    printf("Size of compressed array: %d", size);

    return 0;
}