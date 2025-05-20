//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char *src, int src_size, char *dest, int *dest_size)
{
    int i, j, count = 0, run_length = 1, flag = 0;
    char prev = '\0';

    for (i = 0; i < src_size; i++)
    {
        if (prev == src[i])
        {
            run_length++;
        }
        else
        {
            if (run_length > 1)
            {
                dest[count++] = prev;
                dest[count++] = run_length - 1;
            }
            prev = src[i];
            run_length = 1;
        }

        if (i == src_size - 1)
        {
            if (run_length > 1)
            {
                dest[count++] = prev;
                dest[count++] = run_length - 1;
            }
        }
    }

    *dest_size = count;
}

int main()
{
    char *src = "aabbbbcccc";
    int src_size = 11;
    char *dest = NULL;
    int dest_size = 0;

    compress(src, src_size, dest, &dest_size);

    printf("Compressed data: ");
    for (int i = 0; i < dest_size; i++)
    {
        printf("%c ", dest[i]);
    }

    printf("\n");
    printf("Number of bytes saved: %d", dest_size - src_size);

    return 0;
}