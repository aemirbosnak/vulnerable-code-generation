//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char compressed_buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;
    int compressed_size = 0;

    // Read data from the input stream
    printf("Enter data: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the size of the buffer
    buffer_size = strlen(buffer) + 1;

    // Compress the data
    compress(buffer, compressed_buffer, buffer_size, compressed_size);

    // Print the compressed data
    printf("Compressed data: ");
    printf("%s", compressed_buffer);

    return 0;
}

int compress(char *buffer, char *compressed_buffer, int buffer_size, int *compressed_size)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char previous_character = '\0';

    // Iterate over the buffer
    for (i = 0; i < buffer_size; i++)
    {
        // Count the number of consecutive characters
        if (buffer[i] == previous_character)
        {
            count++;
        }
        else
        {
            // Write the previous character and its count to the compressed buffer
            compressed_buffer[j++] = previous_character;
            compressed_buffer[j++] = count;

            // Reset the count and update the previous character
            count = 1;
            previous_character = buffer[i];
        }
    }

    // Write the final character and its count to the compressed buffer
    compressed_buffer[j++] = previous_character;
    compressed_buffer[j++] = count;

    // Calculate the size of the compressed data
    *compressed_size = j;

    return 0;
}