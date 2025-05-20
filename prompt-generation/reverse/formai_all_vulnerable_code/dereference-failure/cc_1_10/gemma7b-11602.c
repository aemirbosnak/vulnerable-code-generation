//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **buf, int *size)
{
    int i, j, count = 1, run_length = 1;
    char prev = '\0';

    for (i = 0; i < *size; i++)
    {
        if (*buf[i] == prev)
        {
            run_length++;
        }
        else
        {
            if (run_length > 1)
            {
                *buf[i - 1] = (run_length - 1) + 'a';
            }
            prev = *buf[i];
            run_length = 1;
        }
    }

    *size = i + 1;
}

int main()
{
    char *buf = malloc(MAX_SIZE);
    buf[0] = 'a';
    buf[1] = 'a';
    buf[2] = 'b';
    buf[3] = 'b';
    buf[4] = 'c';
    buf[5] = 'c';
    buf[6] = 'c';

    int size = 7;

    compress(&buf, &size);

    printf("Compressed size: %d\n", size);

    free(buf);

    return 0;
}