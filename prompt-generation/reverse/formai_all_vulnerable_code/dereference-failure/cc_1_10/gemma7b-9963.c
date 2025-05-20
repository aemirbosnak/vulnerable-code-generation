//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_URL_LEN 256

void sanitize_url(char *url)
{
    char *ptr = url;
    char *start = NULL;
    char *end = NULL;

    // Strip leading and trailing spaces
    while (*ptr && isspace(*ptr))
    {
        ptr++;
    }

    // Find the start of the URL
    while (*ptr && !isalnum(*ptr))
    {
        ptr++;
    }

    // Find the end of the URL
    end = strchr(ptr, ';') ? strchr(ptr, ';') : strchr(ptr, '?');

    // Remove invalid characters
    if (start)
    {
        char *p = start;
        while (p && p < end)
        {
            if (!isalnum(*p) && *p != '-' && *p != '_')
            {
                *p = '_';
            }
            p++;
        }
    }

    // Normalize the URL
    if (end)
    {
        char *p = end - 1;
        while (*p && isspace(*p))
        {
            *p = '_';
            p--;
        }
    }

    // Copy the sanitized URL to the original buffer
    strcpy(url, start);
}

int main()
{
    char url[MAX_URL_LEN] = "  foo bar!@#$%^&*()_+-?~";
    sanitize_url(url);
    printf("%s\n", url);

    return 0;
}