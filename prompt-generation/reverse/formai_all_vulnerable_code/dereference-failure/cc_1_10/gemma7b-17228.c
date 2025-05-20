//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void compress(char **buf, int *size)
{
    int i, j, k = 0, run = 1, count = 1;
    char prev = '\0';

    for (i = 0; i < *size; i++)
    {
        if (prev == buf[i])
        {
            count++;
        }
        else
        {
            if (run > 1)
            {
                buf[k++] = run - 1;
                buf[k++] = prev;
            }
            prev = buf[i];
            run = 1;
            count = 1;
        }
    }

    if (run > 1)
    {
        buf[k++] = run - 1;
        buf[k++] = prev;
    }

    *size = k;
}

int main()
{
    char *buf = "aabbbbccccca";
    int size = 13;

    compress(&buf, &size);

    printf("Compressed buffer:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", buf[i]);
    }

    printf("\nOriginal size: %d", size);
    printf("\nCompressed size: %d", size);

    return 0;
}