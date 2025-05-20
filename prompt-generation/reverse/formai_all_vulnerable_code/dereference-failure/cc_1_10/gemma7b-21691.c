//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url)
{
    char *p = url;
    char *start = NULL;
    char *end = NULL;

    // Remove leading and trailing spaces
    while (*p && isspace(*p))
    {
        p++;
    }
    while (*p && isspace(*p) && start == NULL)
    {
        start = p;
        p++;
    }

    // Remove invalid characters
    end = strchr(start, '/');
    if (end)
    {
        while (*end && !isalnum(*end))
        {
            end++;
        }
    }

    // Normalize case and remove unnecessary characters
    for (p = start; p < end; p++)
    {
        *p = tolower(*p);
        if (*p == '_')
        {
            *p = '\0';
        }
    }

    // Copy sanitized URL to original string
    if (start)
    {
        memcpy(url, start, end - start);
    }
}

int main()
{
    char url[MAX_URL_LENGTH] = "  abc/xyz?a=b&c=d  ";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}