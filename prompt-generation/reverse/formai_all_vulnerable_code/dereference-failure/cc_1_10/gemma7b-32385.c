//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

int main()
{
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove invalid characters
     sanitized_url[0] = '\0';
    int i = 0;
    for (i = 0; url[i] != '\0'; i++)
    {
        if (!isalnum(url[i]) && url[i] != '/' && url[i] != '.')
        {
            continue;
        }
        sanitized_url[i] = url[i];
    }

    // Remove duplicate slashes
    char *p = sanitized_url;
    char *q = sanitized_url;
    while (p)
    {
        if (q && *p == *q && *(q-1) == '/')
        {
            p++;
            continue;
        }
        q = p;
        p++;
    }

    // Add a trailing slash if necessary
    if (sanitized_url[0] != '/')
    {
        sprintf(sanitized_url + strlen(sanitized_url), "/");
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}