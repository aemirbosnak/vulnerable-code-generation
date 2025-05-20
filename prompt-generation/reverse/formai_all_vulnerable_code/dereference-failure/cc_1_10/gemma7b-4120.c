//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Remove leading and trailing spaces
    while (*p && isspace(*p))
    {
        p++;
    }
    while (*q && isspace(*q))
    {
        q--;
    }

    // Convert to lowercase and remove special characters
    for (; *p && *p != '\0'; p++)
    {
        *p = tolower(*p);
        if (!isalnum(*p) && *p != '-' && *p != '_')
        {
            *p = '\0';
        }
    }

    // Normalize special characters
    char normalized_url[MAX_URL_LENGTH];
    int i = 0;
    for (p = url; *p && *p != '\0'; p++)
    {
        if (*p == '-')
        {
            normalized_url[i++] = '_';
        }
        else
        {
            normalized_url[i++] = *p;
        }
    }
    normalized_url[i] = '\0';

    // Copy the sanitized URL to the original string
    strcpy(url, normalized_url);
}

int main()
{
    char url[MAX_URL_LENGTH] = "  abc-123!@#$%^&*()_+-~  ";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}