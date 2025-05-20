//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **arr, int size)
{
    int i, count = 0, flag = 0, prev = -1;
    char *ptr = *arr;

    for (i = 0; i < size; i++)
    {
        if (prev == ptr[i])
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                flag = 1;
                prev = ptr[i];
                *arr = realloc(*arr, MAX_SIZE);
                arr = &*arr;
                *arr++ = prev;
                *arr++ = count;
            }
            prev = ptr[i];
            count = 1;
        }
    }

    if (flag)
    {
        *arr = realloc(*arr, MAX_SIZE);
        arr = &*arr;
        *arr++ = prev;
        *arr++ = count;
    }
}

int main()
{
    char arr[] = "aabbbbcccc";
    int size = sizeof(arr) / sizeof(char);

    compress(&arr, size);

    printf("%s", arr);

    return 0;
}