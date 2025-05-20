//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *compressed_size, int original_size)
{
    int i, j, count = 0, current_symbol = -1, previous_symbol = -1;
    *compressed_size = 0;

    for (i = 0; i < original_size; i++)
    {
        if (buffer[i] != previous_symbol)
        {
            if (current_symbol != -1)
            {
                (*compressed_size)++;
                buffer[*compressed_size - 1] = count;
            }

            current_symbol = buffer[i];
            count = 1;
        }
        else
        {
            count++;
        }

        previous_symbol = buffer[i];
    }

    if (current_symbol != -1)
    {
        (*compressed_size)++;
        buffer[*compressed_size - 1] = count;
    }

    *compressed_size = (*compressed_size) + 1;
}

int main()
{
    char buffer[] = "aabbbbcccc";
    int original_size = sizeof(buffer) / sizeof(char);
    int compressed_size = 0;

    compress(buffer, &compressed_size, original_size);

    printf("Compressed size: %d\n", compressed_size);

    return 0;
}