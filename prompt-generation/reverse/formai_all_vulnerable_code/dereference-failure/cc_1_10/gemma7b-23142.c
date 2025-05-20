//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

void sanitize_user_input(char **buffer)
{
    char *tmp_buffer = NULL;
    int i = 0, len = 0, valid_chars = 0;

    if (*buffer == NULL)
    {
        return;
    }

    len = strlen(*buffer);

    // Allocate temporary buffer to store sanitized input
    tmp_buffer = malloc(len + 1);
    if (tmp_buffer == NULL)
    {
        return;
    }

    // Iterate over original buffer to remove invalid characters
    for (i = 0; i < len; i++)
    {
        if (((*buffer)[i] >= 'a' && (*buffer)[i] <= 'z') ||
            ((*buffer)[i] >= 'A' && (*buffer)[i] <= 'Z') ||
            ((*buffer)[i] >= '0' && (*buffer)[i] <= '9') ||
            ((*buffer)[i] == ' ') ||
            ((*buffer)[i] == '\n')
           )
        {
            valid_chars++;
            (tmp_buffer)[valid_chars - 1] = (*buffer)[i];
        }
    }

    // Free original buffer and allocate new buffer for sanitized input
    free(*buffer);
    *buffer = malloc(valid_chars);

    // Copy sanitized input from temporary buffer to new buffer
    memcpy(*buffer, tmp_buffer, valid_chars);

    // Free temporary buffer
    free(tmp_buffer);
}

int main()
{
    char *user_input = NULL;

    // Get user input
    printf("Enter a message: ");
    user_input = malloc(MAX_BUFFER_SIZE);
    fgets(user_input, MAX_BUFFER_SIZE, stdin);

    // Sanitize user input
    sanitize_user_input(&user_input);

    // Print sanitized user input
    printf("Sanitized user input: %s", user_input);

    // Free memory
    free(user_input);

    return 0;
}