//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 256

char *sanitize_url(char *url)
{
    char *p, *q, *r, *s;
    int i, len = 0;

    if (!url)
    {
        return NULL;
    }

    len = strlen(url);
    s = malloc(MAX_URL_LEN);

    r = s;
    for (p = url; *p; p++)
    {
        if (*p == '/')
        {
            for (q = p; *q && *q != '/'; *q++)
            {
                *r++ = *q;
            }
            *r++ = '/';
        }
        else
        {
            *r++ = *p;
        }
    }

    *r = NULL;
    return s;
}

int main()
{
    char *url = "This is a URL with/some special characters!#$%^&*";
    char *sanitized_url = sanitize_url(url);

    if (sanitized_url)
    {
        printf("Sanitized URL: %s\n", sanitized_url);
    }

    return 0;
}