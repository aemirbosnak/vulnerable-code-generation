//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char **buffer)
{
    char *p = *buffer;
    char *end = *buffer + MAX_BUFFER_SIZE;
    char *start = *buffer;

    // Remove leading and trailing whitespace
    while (p < end && isspace(*p))
    {
        *start = ++p;
    }

    // Convert uppercase letters to lowercase
    while (p < end && isupper(*p))
    {
        *p = tolower(*p);
    }

    // Remove special characters
    while (p < end && strchr("!@#$%^&*()_+-={}[]|\\:", *p))
    {
        *p = NULL;
    }

    // Normalize whitespace
    char *prev = NULL;
    p = *buffer;
    while (p < end)
    {
        if (isspace(*p) && prev)
        {
            *prev = ' ';
        }
        prev = p;
        p++;
    }

    // Trim trailing whitespace
    while (p > start && isspace(*p))
    {
        *p = NULL;
    }

    *buffer = start;
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter a message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    sanitize_user_input(&buffer);

    printf("Sanitized message: %s", buffer);

    return 0;
}