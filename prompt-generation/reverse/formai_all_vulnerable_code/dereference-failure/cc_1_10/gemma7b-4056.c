//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **buf, int **len)
{
    int i = 0, j = 0, count = 1, run = 0;
    char prev = '\0';

    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == prev)
        {
            run++;
        }
        else
        {
            prev = buf[i];
            if (run)
            {
                buf[j++] = (run - 1) + 'a';
            }
            buf[j++] = buf[i];
            run = 1;
        }
    }

    *len = j;
    return;
}

int main()
{
    char **buf = malloc(MAX);
    int len = MAX;

    buf[0] = 'a';
    buf[1] = 'a';
    buf[2] = 'b';
    buf[3] = 'b';
    buf[4] = 'b';
    buf[5] = 'c';
    buf[6] = 'c';
    buf[7] = 'c';
    buf[8] = '\0';

    compress(buf, &len);

    printf("Compressed buffer:");
    for (int i = 0; buf[i] != '\0'; i++)
    {
        printf(" %c", buf[i]);
    }

    printf("\nNumber of bytes compressed: %d", len);

    free(buf);

    return 0;
}