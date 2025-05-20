//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buf, int *size)
{
    int i, j, count = 0, prev = -1, run_length = 0;
    char **new_buf = NULL;

    new_buf = malloc((*size) * sizeof(char *));

    for (i = 0; i < *size; i++)
    {
        if (prev == buf[i])
        {
            run_length++;
        }
        else
        {
            if (prev != -1)
            {
                new_buf[count++] = prev;
                new_buf[count++] = run_length;
            }

            prev = buf[i];
            run_length = 1;
        }
    }

    *size = count;
    *buf = new_buf;
}

int main()
{
    char *buf = "aabbbbcccccaa";
    int size = strlen(buf);

    compress(&buf, &size);

    printf("Compressed buffer: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", buf[i]);
    }

    printf("\n");

    printf("Original buffer size: %d\n", size);
    printf("Compressed buffer size: %d\n", size);

    return 0;
}