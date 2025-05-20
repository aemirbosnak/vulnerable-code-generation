//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url)
{
    char *new_url = malloc(MAX_URL_LENGTH);
    int i = 0, j = 0, valid = 0;

    for (; i < strlen(url); i++)
    {
        char character = url[i];

        // Normalize character case
        character = tolower(character);

        // Check for valid characters
        if ((character >= 'a' && character <= 'z') ||
            (character >= '0' && character <= '9') ||
            (character == '.' || character == '-' || character == '_')
           )
        {
            new_url[j] = character;
            j++;
            valid = 1;
        }
    }

    if (!valid)
    {
        new_url = NULL;
    }

    return new_url;
}

int main()
{
    char *url = "This is a sample URL with special characters!#!$%^&*()";
    char *sanitized_url = sanitize_url(url);

    if (sanitized_url)
    {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }
    else
    {
        printf("Error sanitizing URL.\n");
    }

    return 0;
}