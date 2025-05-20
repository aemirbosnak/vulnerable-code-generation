//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char *src, int src_size, char *dest, int *dest_size)
{
    int i = 0, j = 0, count = 1, run_length = 1;
    char previous = '\0';

    for (i = 0; i < src_size; i++)
    {
        if (src[i] == previous)
        {
            run_length++;
        }
        else
        {
            dest[j++] = previous;
            dest[j++] = count - 1;
            previous = src[i];
            count = 1;
            run_length = 1;
        }
    }

    dest[j++] = previous;
    dest[j++] = count - 1;

    *dest_size = j;
}

int main()
{
    char *src = "aabbbbcccc";
    int src_size = 10;
    char *dest = (char *)malloc(MAX_SIZE);
    int dest_size = 0;

    compress(src, src_size, dest, &dest_size);

    printf("Compressed data: ");
    for (int i = 0; i < dest_size; i++)
    {
        printf("%c ", dest[i]);
    }

    printf("\n");

    printf("Original data size: %d", src_size);

    printf("\n");

    printf("Compressed data size: %d", dest_size);

    return 0;
}