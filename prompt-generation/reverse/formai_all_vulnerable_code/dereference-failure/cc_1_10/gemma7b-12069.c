//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *buffer_size, int **compressed_buffer, int *compressed_size)
{
    int i, j, k, count = 0, previous_char = '\0';
    char compressed_data[MAX_BUFFER_SIZE];

    for (i = 0; i < *buffer_size; i++)
    {
        if (*buffer[i] == previous_char)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                compressed_data[k++] = previous_char;
                compressed_data[k++] = count - 1;
            }
            previous_char = *buffer[i];
            count = 1;
        }
    }

    *compressed_size = k;
    *compressed_buffer = compressed_data;
}

int main()
{
    char buffer[] = "aabbbbcccccaabb";
    int buffer_size = sizeof(buffer) / sizeof(char);

    int compressed_buffer[MAX_BUFFER_SIZE];
    int compressed_size = 0;

    compress(&buffer, &buffer_size, &compressed_buffer, &compressed_size);

    printf("Original buffer:\n");
    for (int i = 0; i < buffer_size; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\nCompressed buffer:\n");
    for (int i = 0; i < compressed_size; i++)
    {
        printf("%c ", compressed_buffer[i]);
    }

    return 0;
}