//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *ptr = url;
    char *new_url = NULL;
    int i = 0;
    int length = 0;

    // Calculate the length of the URL
    while (*ptr)
    {
        length++;
        ptr++;
    }

    // Allocate memory for the new URL
    new_url = malloc(length);

    // Copy the original URL to the new URL
    memcpy(new_url, url, length);

    // Remove all special characters
    ptr = new_url;
    while (*ptr)
    {
        if (*ptr < 'a' || *ptr > 'z')
        {
            *ptr = '_';
        }
        ptr++;
    }

    // Replace all spaces with underscores
    ptr = new_url;
    while (*ptr)
    {
        if (*ptr == ' ')
        {
            *ptr = '_';
        }
        ptr++;
    }

    // Remove all trailing punctuation
    ptr = new_url;
    while (*ptr && *ptr != '\0')
    {
        if (*ptr >= '!' && *ptr <= '/')
        {
            *ptr = '\0';
        }
        ptr++;
    }

    // Return the sanitized URL
    printf("%s\n", new_url);

    // Free the memory allocated for the new URL
    free(new_url);
}

int main()
{
    char url[MAX_URL_LENGTH] = "This is a URL with special characters!#$%&*()_";

    sanitize_url(url);

    return 0;
}