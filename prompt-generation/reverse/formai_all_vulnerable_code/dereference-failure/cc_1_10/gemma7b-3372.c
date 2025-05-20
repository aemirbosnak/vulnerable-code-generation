//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void compress(char **buf, int *len)
{
    int i, j, k = 0, run = 1;
    char prev = '\0';

    for (i = 0; i < *len; i++)
    {
        if (prev == buf[i])
        {
            run++;
        }
        else
        {
            if (run > 1)
            {
                buf[k++] = prev;
                buf[k++] = run - 1;
            }
            prev = buf[i];
            run = 1;
        }
    }

    if (run > 1)
    {
        buf[k++] = prev;
        buf[k++] = run - 1;
    }

    *len = k;
}

int main()
{
    char *buf = "HELLO WORLD!!!";
    int len = strlen(buf);

    compress(&buf, &len);

    printf("Compressed: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c ", buf[i]);
    }

    printf("\n");

    printf("Original: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c ", buf[i]);
    }

    printf("\n");

    return 0;
}