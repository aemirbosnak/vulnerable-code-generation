//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char **buffer)
{
    char *p = *buffer;
    char *end = p + MAX_BUFFER_SIZE;

    // Remove leading and trailing whitespace
    while (p < end && isspace(*p))
    {
        *p++ = '\0';
    }

    // Trim excessive whitespace
    char *prev = p;
    while (p < end && !isspace(*p))
    {
        prev = p;
        p++;
    }
    if (prev != p)
    {
        *prev = '\0';
    }

    // Convert to lowercase
    p = *buffer;
    while (p < end)
    {
        *p = tolower(*p);
        p++;
    }
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter a string: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    sanitize_user_input(&buffer);

    printf("Sanitized string: %s\n", buffer);

    return 0;
}