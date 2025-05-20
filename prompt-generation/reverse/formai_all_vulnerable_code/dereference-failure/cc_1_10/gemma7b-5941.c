//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;
    int i = 0;

    printf("Enter text: ");

    // Get text from user and store it in the buffer
    while (buffer_size < MAX_BUFFER_SIZE && (buffer[buffer_size] = getchar()) != '\n')
    {
        buffer_size++;
    }

    // Increment the buffer size by one for the null terminator
    buffer_size++;

    // Compress the text
    int compressed_size = compress(buffer, buffer_size);

    // Print the compressed text
    printf("Compressed text: ");
    for (i = 0; i < compressed_size; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    return 0;
}

int compress(char *buffer, int buffer_size)
{
    int i = 0;
    int compressed_size = 0;
    int repeat = 1;

    // Iterate over the buffer
    for (i = 0; i < buffer_size; i++)
    {
        // If the current character is the same as the previous character, increment the repeat count
        if (buffer[i] == buffer[i - 1])
        {
            repeat++;
        }
        else
        {
            // If the repeat count is greater than one, write the character and its repeat count
            if (repeat > 1)
            {
                buffer[compressed_size++] = buffer[i - 1] - 'a' + 1;
                buffer[compressed_size++] = repeat - 1;
            }
            else
            {
                // Write the character to the compressed buffer
                buffer[compressed_size++] = buffer[i];
            }

            repeat = 1;
        }
    }

    // If the repeat count is greater than one for the last character, write it
    if (repeat > 1)
    {
        buffer[compressed_size++] = buffer[i - 1] - 'a' + 1;
        buffer[compressed_size++] = repeat - 1;
    }

    return compressed_size;
}