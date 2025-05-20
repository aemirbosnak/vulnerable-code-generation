//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    char text[] = "Romeo and Juliet is a tragedy by William Shakespeare.";
    int text_size = sizeof(text) - 1;
    int compressed_size = 0;
    char *compressed_text = NULL;

    // Allocate memory for compressed text
    compressed_text = malloc(MAX_SIZE);

    // Compress text
    compress(text, text_size, compressed_text, &compressed_size);

    // Print compressed text
    printf("Compressed text: %s", compressed_text);

    // Free memory
    free(compressed_text);

    return 0;
}

int compress(char *text, int text_size, char *compressed_text, int *compressed_size)
{
    int i = 0;
    int j = 0;
    int count = 1;
    char previous_char = '\0';

    // Iterate over the text
    for (i = 0; i < text_size; i++)
    {
        // If the current character is the same as the previous character, increment the count
        if (text[i] == previous_char)
        {
            count++;
        }
        else
        {
            // If the count is greater than 1, write the character and the count
            if (count > 1)
            {
                compressed_text[j++] = text[i] - 'a' + 1;
                compressed_text[j++] = count - 1;
            }
            else
            {
                compressed_text[j++] = text[i];
            }

            previous_char = text[i];
            count = 1;
        }
    }

    // Write the remaining character and the count
    if (count > 1)
    {
        compressed_text[j++] = text[i] - 'a' + 1;
        compressed_text[j++] = count - 1;
    }

    // Calculate the compressed size
    *compressed_size = j;

    return 0;
}