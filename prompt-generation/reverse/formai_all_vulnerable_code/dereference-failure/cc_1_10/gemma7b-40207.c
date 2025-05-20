//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *start = NULL;
    char *end = NULL;

    // Strip leading and trailing spaces
    while (isspace(*p))
    {
        p++;
    }

    // Find the start of the URL
    if (p != url)
    {
        start = p;
    }

    // Find the end of the URL
    end = strchr(p, '#');
    if (end)
    {
        *end = '\0';
    }

    // Normalize case and remove special characters
    p = start;
    while (*p)
    {
        *p = tolower(*p);
        if (!isalnum(*p) && *p != '-')
        {
            *p = '\0';
        }
        p++;
    }

    // Copy the sanitized URL to the original string
    if (start)
    {
        strcpy(url, start);
    }
}

int main()
{
    char url[MAX_URL_LENGTH] = "This is a sample URL with spaces, special characters, and case sensitivity.";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}