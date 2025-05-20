//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

char *sanitize_url(char *url)
{
    char *normalized_url = NULL;
    char *p = NULL;
    int length = 0;
    int i = 0;

    if (!url)
    {
        return NULL;
    }

    // Calculate the length of the URL.
    length = strlen(url) + 1;

    // Allocate memory for the normalized URL.
    normalized_url = (char *)malloc(length);

    // Copy the URL into the normalized URL.
    memcpy(normalized_url, url, length);

    // Normalize the URL.
    p = normalized_url;

    // Remove all special characters.
    while (*p)
    {
        if (*p < 'a' || *p > 'z')
        {
            *p = '_';
        }
        p++;
    }

    // Remove all leading and trailing spaces.
    p = normalized_url;
    while (*p == ' ')
    {
        *p = '\0';
        p++;
    }

    // Return the normalized URL.
    return normalized_url;
}

int main()
{
    char *url = "This is a URL with special characters!#$%&*()";
    char *normalized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Normalized URL: %s\n", normalized_url);

    free(normalized_url);

    return 0;
}