//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *start = url;
    char *end = url + MAX_URL_LENGTH - 1;

    // Remove all non-alphanumeric characters
    while (p < end && *p)
    {
        if (!isalnum(*p))
        {
            *p = '\0';
        } else
        {
            p++;
        }
    }

    // Normalize case
    start = url;
    while (*start)
    {
        *start = tolower(*start);
        start++;
    }

    // Remove duplicate consecutive slashes
    p = url;
    while (p < end && *p)
    {
        if (*(p-1) == '/' && *p == '/')
        {
            *(p-1) = '\0';
        } else
        {
            p++;
        }
    }

    // Return the sanitized URL
    return;
}

int main()
{
    char url[MAX_URL_LENGTH] = "This is a sample URL with special characters!#$%^&*()";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}