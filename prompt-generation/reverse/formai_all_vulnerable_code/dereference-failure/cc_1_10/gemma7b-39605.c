//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char **buffer)
{
    char *p = *buffer;
    char *end = p + MAX_BUFFER_SIZE;

    // Remove leading and trailing whitespaces
    while (p != end && *p == ' ')
    {
        *p = '\0';
        p++;
    }

    // Normalize upper case letters
    while (p != end && *p)
    {
        *p = tolower(*p);
        p++;
    }

    // Remove special characters
    while (p != end && (*p < 'a' || *p > 'z'))
    {
        *p = '\0';
        p++;
    }

    // Trim trailing whitespaces
    while (p != end && *p == ' ')
    {
        *p = '\0';
        p--;
    }
}

int main()
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    printf("Enter a message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    sanitize_user_input(&buffer);

    printf("Sanitized message: %s", buffer);

    free(buffer);

    return 0;
}