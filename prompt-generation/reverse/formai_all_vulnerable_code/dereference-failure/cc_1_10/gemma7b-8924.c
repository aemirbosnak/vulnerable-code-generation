//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char **str, int *size)
{
    char **ptr = str;
    int i = 0, j = 0, count = 1;
    char prev = '\0';

    for (i = 0; ptr[i] != '\0'; i++)
    {
        if (prev == ptr[i])
        {
            count++;
        }
        else
        {
            prev = ptr[i];
            if (count > 1)
            {
                *size -= count - 1;
                for (j = i - count + 1; j >= 0; j--)
                {
                    ptr[j] = ptr[j + 1];
                }
                count = 1;
            }
        }
    }

    if (count > 1)
    {
        *size -= count - 1;
        for (j = i - count + 1; j >= 0; j--)
        {
            ptr[j] = ptr[j + 1];
        }
    }

    return;
}

int main()
{
    char str[] = "aabbbbcccc";
    int size = strlen(str) + 1;

    compress(&str, &size);

    printf("Compressed string: %s", str);
    printf("\nCompressed size: %d", size);

    return 0;
}