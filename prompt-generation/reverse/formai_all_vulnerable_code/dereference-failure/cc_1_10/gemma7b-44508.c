//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;
    int flag = 0;

    // Remove all non-alphanumeric characters
    while (*p)
    {
        if (!isalnum(*p) && *p != '-' && *p != '_')
        {
            p++;
            continue;
        }

        *q = *p;
        q++;

        flag = 1;
    }

    // Remove trailing slashes
    if (flag && url[strlen(url) - 1] == '/')
    {
        url[strlen(url) - 1] = '\0';
    }

    // Normalize case
    for (p = url; *p; p++)
    {
        *p = tolower(*p);
    }
}

int main()
{
    char url[MAX_URL_LENGTH] = "This is a sample URL with special characters!/#$%^&*";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}