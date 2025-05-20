//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;
    int i = 0;

    // Strip leading and trailing spaces
    while (isspace(*p))
    {
        p++;
    }
    while (isspace(*q))
    {
        q--;
    }

    // Convert uppercase letters to lowercase
    while (*p)
    {
        *p = tolower(*p);
        p++;
    }

    // Remove invalid characters
    while (*q)
    {
        if (!isalnum(*q) && *q != '-' && *q != '_')
        {
            *q = '\0';
        }
        else
        {
            q++;
        }
    }

    // Normalize relative URLs
    if (url[0] == '/')
    {
        sprintf(url, "%s", url + 1);
    }

    // Return the sanitized URL
    return;
}

int main()
{
    char url[MAX_URL_LENGTH] = "  http://example.com/my-url?query=string&param=123#fragment  ";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}