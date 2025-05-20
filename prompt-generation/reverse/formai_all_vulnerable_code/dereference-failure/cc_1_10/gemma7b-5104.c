//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *sanitized_buffer = NULL;
    int buffer_size = 0;
    int i = 0;
    int flag = 0;

    printf("Enter a string: ");

    // Get the user input and store it in the buffer
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Calculate the size of the user input
    buffer_size = strlen(buffer) + 1;

    // Allocate memory for the sanitized buffer
    sanitized_buffer = malloc(buffer_size);

    // Sanitize the user input
    for (i = 0; i < buffer_size; i++)
    {
        // Convert all letters to lowercase
        buffer[i] = tolower(buffer[i]);

        // Remove all non-alphanumeric characters
        if (!isalnum(buffer[i]))
        {
            buffer[i] = '\0';
        }

        // Remove all consecutive repeated characters
        flag = 0;
        for (int j = i - 1; j >= 0 && buffer[j] == buffer[i]; j--)
        {
            buffer[i] = '\0';
            flag = 1;
        }

        // If there are no repeated characters, move the character to the sanitized buffer
        if (!flag)
        {
            sanitized_buffer[i] = buffer[i];
        }
    }

    // Print the sanitized string
    printf("Sanitized string: %s\n", sanitized_buffer);

    // Free the allocated memory
    free(sanitized_buffer);

    return 0;
}