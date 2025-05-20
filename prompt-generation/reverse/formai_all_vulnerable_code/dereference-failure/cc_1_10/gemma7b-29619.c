//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 255

void sanitize_url(char **url)
{
    char *p = *url;
    char *q = NULL;
    int i = 0;

    while (*p)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *q = malloc(i + 1);
            memcpy(q, p, i);
            q[i] = '\0';
            *url = q;
            i = 0;
        }
        else if (*p == '/' || *p == '\\')
        {
            *q = malloc(i + 1);
            memcpy(q, p, i);
            q[i] = '\0';
            *url = q;
            i = 0;
        }
        else if (*p == '%')
        {
            i++;
        }
        else
        {
            i++;
        }

        p++;
    }

    *url = NULL;
}

int main()
{
    char *url = "This is a url with special characters!%20$#!";

    sanitize_url(&url);

    printf("Sanitized URL: %s\n", url);

    free(url);

    return 0;
}