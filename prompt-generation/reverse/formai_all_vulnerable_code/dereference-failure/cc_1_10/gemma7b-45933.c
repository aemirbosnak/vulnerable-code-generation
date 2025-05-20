//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *compressed_size, int original_size)
{
    int i, j, count = 0, run_length = 1;
    char previous_char = '\0';

    *compressed_size = 0;

    for (i = 0; i < original_size; i++)
    {
        if (previous_char == buffer[i])
        {
            run_length++;
        }
        else
        {
            if (run_length > 1)
            {
                *compressed_size += 2 + log(run_length) / 8;
            }
            else
            {
                *compressed_size++;
            }

            previous_char = buffer[i];
            run_length = 1;
        }
    }

    if (run_length > 1)
    {
        *compressed_size += 2 + log(run_length) / 8;
    }

    return;
}

int main()
{
    char buffer[] = "aabbbbcccc";
    int original_size = sizeof(buffer) - 1;
    int compressed_size = 0;

    compress(buffer, &compressed_size, original_size);

    printf("Compressed size: %d\n", compressed_size);

    return 0;
}