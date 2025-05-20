//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LENGTH 512

int sanitize_url(char *url)
{
    char *p = url;
    char *start = NULL;
    char *end = NULL;

    // Remove all leading and trailing spaces
    while (isspace(*p))
    {
        p++;
    }

    // Find the start of the URL
    while (*p && !isalnum(*p))
    {
        p++;
    }

    // Find the end of the URL
    end = strchr(p, '/');
    if (!end)
    {
        end = strchr(p, '\0');
    }

    // If the URL is too long, truncate it
    if (end - p > MAX_URL_LENGTH)
    {
        end = p + MAX_URL_LENGTH;
    }

    // Normalize the URL
    *start = strndup(p, end - p);

    return 0;
}

int main()
{
    char url[MAX_URL_LENGTH] = "  abc.com/a/b?c=1&d=2   ";

    sanitize_url(url);

    printf("%s\n", url);

    return 0;
}