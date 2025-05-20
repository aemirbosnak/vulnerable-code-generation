//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;

    // Get the input text from the user
    printf("Enter text: ");
    getline(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the compressed size of the text
    int compressed_size = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        char current_char = buffer[i];
        int occurrences = 0;
        for (int j = i; buffer[j] == current_char; j++)
        {
            occurrences++;
        }
        compressed_size += 1 + occurrences * 2;
    }

    // Allocate memory for the compressed text
    char* compressed_text = malloc(compressed_size);

    // Compress the text
    int offset = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        char current_char = buffer[i];
        int occurrences = 0;
        for (int j = i; buffer[j] == current_char; j++)
        {
            occurrences++;
        }
        compressed_text[offset++] = current_char;
        if (occurrences > 1)
        {
            compressed_text[offset++] = occurrences - 1;
        }
    }

    // Print the compressed text
    printf("Compressed text: ");
    for (int i = 0; compressed_text[i] != '\0'; i++)
    {
        printf("%c", compressed_text[i]);
    }

    // Free the memory
    free(compressed_text);

    return 0;
}