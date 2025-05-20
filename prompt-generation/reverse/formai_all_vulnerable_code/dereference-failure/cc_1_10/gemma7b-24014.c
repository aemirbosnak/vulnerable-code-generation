//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter a string: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Convert the string into a binary representation
    int string_length = strlen(buffer);
    unsigned int binary_length = string_length * 8;
    unsigned char *binary = (unsigned char *)malloc(binary_length);
    int i = 0;
    for (i = 0; i < string_length; i++)
    {
        binary[i] = buffer[i] << 8 | buffer[i] & 0xFF;
    }

    // Compress the binary data
    unsigned int compressed_length = compress(binary, binary_length);

    // Print the compressed data
    printf("Compressed data: ");
    for (i = 0; i < compressed_length; i++)
    {
        printf("%x ", binary[i]);
    }

    // Free the memory
    free(binary);

    return 0;
}

int compress(unsigned char *data, int length)
{
    int i = 0;
    int compressed_length = 0;
    unsigned char previous_byte = data[0];
    int consecutive_repeats = 1;

    for (i = 1; i < length; i++)
    {
        if (data[i] == previous_byte)
        {
            consecutive_repeats++;
        }
        else
        {
            previous_byte = data[i];
            consecutive_repeats = 1;
        }

        // Compress the data
        if (consecutive_repeats > 1)
        {
            compressed_length++;
            data[compressed_length - 1] = consecutive_repeats - 1;
        }
    }

    return compressed_length;
}