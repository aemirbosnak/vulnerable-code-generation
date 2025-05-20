//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char **buffer)
{
    char *p = *buffer;
    char *q = *buffer;
    int len = 0;

    // Remove leading and trailing whitespace
    while (*p && isspace(*p))
    {
        p++;
    }

    // Remove unnecessary characters
    while (*q && !isspace(*q))
    {
        if (!isalnum(*q))
        {
            q++;
        }
        else
        {
            len++;
            *q = p;
            p++;
        }
    }

    // Null-terminate the string
    *buffer = realloc(*buffer, len + 1);
    *buffer[len] = '\0';
}

int main()
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *message = "Enter a message: ";

    printf("%s", message);
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    sanitize_user_input(&buffer);

    printf("Your sanitized message is: %s", buffer);

    free(buffer);
    return 0;
}