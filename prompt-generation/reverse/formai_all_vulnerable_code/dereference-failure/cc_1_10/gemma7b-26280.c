//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;

    // Read data from the input stream
    printf("Enter data: ");
    scanf("%s", buffer);

    // Compress the data
    buffer_size = compress(buffer, MAX_BUFFER_SIZE);

    // Print the compressed data
    printf("Compressed data: ");
    for (int i = 0; i < buffer_size; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    return 0;
}

int compress(char *buffer, int buffer_size)
{
    int i = 0;
    int count = 1;
    int compressed_size = 0;

    // Iterate over the buffer
    for (i = 0; i < buffer_size; i++)
    {
        // If the current character is the same as the previous character, increment the count
        if (buffer[i] == buffer[i - 1])
        {
            count++;
        }
        else
        {
            // Write the previous character and its count to the compressed buffer
            compressed_size++;
            buffer[compressed_size - 1] = buffer[i - 1];
            buffer[compressed_size] = count;
            count = 1;
        }
    }

    // Write the last character and its count to the compressed buffer
    compressed_size++;
    buffer[compressed_size - 1] = buffer[i - 1];
    buffer[compressed_size] = count;

    return compressed_size;
}