//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 256

void sanitize_user_input(char **buffer)
{
    char *p = *buffer;
    char *end = p + MAX_BUFFER_SIZE;

    // Strip leading and trailing whitespace
    while (p < end && isspace(*p))
    {
        p++;
    }

    // Convert to uppercase and remove non-alphanumeric characters
    while (p < end && !isalnum(*p))
    {
        p++;
    }

    // Normalize spaces and remove consecutive duplicates
    char previous = '\0';
    while (p < end)
    {
        if (*p == ' ' && previous == ' ')
        {
            p++;
        }
        else
        {
            previous = *p;
            *buffer = p;
        }
    }

    // Null-terminate the string
    *buffer = NULL;
}

int main()
{
    char *buffer = NULL;
    char input[MAX_BUFFER_SIZE];

    printf("Please enter your message: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    sanitize_user_input(&buffer);

    if (buffer)
    {
        printf("Sanitized message: %s\n", buffer);
    }
    else
    {
        printf("Error sanitizing input.\n");
    }

    return 0;
}