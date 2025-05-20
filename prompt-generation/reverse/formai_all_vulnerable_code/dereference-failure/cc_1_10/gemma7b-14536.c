//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *size)
{
    int i = 0, j = 0, count = 1, repeat = 0;
    char prev = '\0';

    for (i = 0; i < *size; i++)
    {
        if (prev == buffer[i])
        {
            repeat++;
        }
        else
        {
            prev = buffer[i];
            repeat = 0;
        }

        if (repeat > 1)
        {
            buffer[j++] = prev;
            buffer[j++] = repeat - 1;
        }
        else
        {
            buffer[j++] = buffer[i];
        }
    }

    *size = j;
}

int main()
{
    char *buffer = NULL;
    int size = 0;

    buffer = malloc(MAX_BUFFER_SIZE);
    size = 10;

    buffer[0] = 'a';
    buffer[1] = 'a';
    buffer[2] = 'b';
    buffer[3] = 'b';
    buffer[4] = 'c';
    buffer[5] = 'c';
    buffer[6] = 'c';
    buffer[7] = 'c';
    buffer[8] = 'a';
    buffer[9] = 'a';

    compress(&buffer, &size);

    printf("Compressed buffer:");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\nOriginal size: %d", size);

    printf("\nCompressed size: %d", size);

    free(buffer);

    return 0;
}