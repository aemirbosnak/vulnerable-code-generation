//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

char* sanitize_user_input(char* buffer)
{
    char* clean_buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0, j = 0;

    // Remove all leading and trailing whitespace
    while (buffer[i] == ' ' || buffer[i] == '\t')
    {
        i++;
    }

    // Remove all consecutive duplicate characters
    while (buffer[i] == buffer[i-1] && i < strlen(buffer))
    {
        i++;
    }

    // Copy the remaining characters to the clean buffer
    while (buffer[i] != '\0')
    {
        clean_buffer[j++] = buffer[i++];
    }

    // Null terminate the clean buffer
    clean_buffer[j] = '\0';

    // Free the original buffer
    free(buffer);

    return clean_buffer;
}

int main()
{
    char* user_input = malloc(MAX_BUFFER_SIZE);
    printf("Enter a string: ");
    fgets(user_input, MAX_BUFFER_SIZE, stdin);

    char* sanitized_input = sanitize_user_input(user_input);

    printf("Sanitized input: %s\n", sanitized_input);

    free(user_input);
    free(sanitized_input);

    return 0;
}