//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;
    char *r = NULL;

    // Remove all non-ASCII characters
    while (*p)
    {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '-' || *p == '_'))
        {
            *q = p;
            *r = NULL;
        }
        else
        {
            q++;
        }

        p++;
    }

    // Remove all consecutive special characters
    if (r)
    {
        char *s = r;
        while (*s)
        {
            if (*s == *r)
            {
                s++;
                r++;
            }
            else
            {
                r = s;
            }
        }
    }

    // Null-terminate the sanitized URL
    *q = NULL;
}

int main()
{
    char url[MAX_URL_LENGTH] = "This is a sample URL with many special characters!#$%^&*()_+-={}[]|\\";

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}