//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *buffer_size)
{
    int i, j, k, count = 0, previous_symbol = -1, previous_count = 0, current_symbol = -1;
    char **compressed_buffer = NULL;

    *buffer_size = (*buffer_size) / 2;

    compressed_buffer = (char**)malloc((*buffer_size) * sizeof(char *));

    for (i = 0; i < *buffer_size; i++)
    {
        k = 0;
        current_symbol = buffer[i];
        for (j = i - 1; j >= 0 && current_symbol == buffer[j]; j--)
        {
            k++;
        }

        if (previous_symbol == current_symbol && previous_count > 0)
        {
            compressed_buffer[count++] = previous_symbol;
            compressed_buffer[count++] = previous_count - 1;
        }
        else
        {
            compressed_buffer[count++] = current_symbol;
            compressed_buffer[count++] = k;
        }

        previous_symbol = current_symbol;
        previous_count = k;
    }

    free(buffer);
    *buffer = compressed_buffer;
    *buffer_size = count;
}

int main()
{
    char *buffer = "aabbbbcccccaa";
    int buffer_size = 12;

    compress(&buffer, &buffer_size);

    printf("Compressed buffer: ");
    for (int i = 0; i < buffer_size; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    printf("Compressed buffer size: %d", buffer_size);

    return 0;
}