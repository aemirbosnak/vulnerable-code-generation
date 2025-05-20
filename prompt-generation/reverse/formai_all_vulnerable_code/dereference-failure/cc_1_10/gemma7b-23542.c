//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *buffer_size, int original_size)
{
    int i, j, k, count = 0, run_length = 1, repetition = 0;
    char prev_char = '\0';

    for (i = 0; i < original_size; i++)
    {
        if (prev_char == buffer[i])
        {
            run_length++;
        }
        else
        {
            if (run_length > 1)
            {
                *buffer_size += 2;
                buffer[(*buffer_size - 1)] = count;
                buffer[(*buffer_size - 2)] = run_length - 1;
            }
            prev_char = buffer[i];
            count = 1;
            run_length = 1;
        }
    }

    if (run_length > 1)
    {
        *buffer_size += 2;
        buffer[(*buffer_size - 1)] = count;
        buffer[(*buffer_size - 2)] = run_length - 1;
    }

    buffer = NULL;
    *buffer_size = 0;
}

int main()
{
    char original_buffer[] = "aabbbbcccccaaabbbb";
    int original_size = sizeof(original_buffer) / sizeof(char);

    char *compressed_buffer = NULL;
    int compressed_size = 0;

    compress(&compressed_buffer, &compressed_size, original_size);

    printf("Original size: %d\n", original_size);
    printf("Compressed size: %d\n", compressed_size);

    return 0;
}