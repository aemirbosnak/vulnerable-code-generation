//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char *sanitize_url(char *url)
{
    char *sanitized_url = malloc(MAX_BUFFER_SIZE);
    memset(sanitized_url, 0, MAX_BUFFER_SIZE);

    // Remove all non-alphanumeric characters
    char *p = url;
    char *q = sanitized_url;
    while (*p)
    {
        if (isalnum(*p))
        {
            *q++ = *p;
        }
        p++;
    }

    // Convert remaining characters to lowercase
    p = sanitized_url;
    while (*p)
    {
        *p = tolower(*p);
        p++;
    }

    // Strip trailing slashes
    if (sanitized_url[strlen(sanitized_url) - 1] == '/')
    {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }

    // Return sanitized URL
    return sanitized_url;
}

int main()
{
    char *url = "This is a url with special characters!#$%&*()_+-";
    char *sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}