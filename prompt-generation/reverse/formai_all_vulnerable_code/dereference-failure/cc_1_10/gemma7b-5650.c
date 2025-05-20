//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

char *sanitize_url(char *url)
{
    char *p = url;
    char *q = url;
    char *r = NULL;
    int i = 0;

    // Allocate memory for the sanitized URL
    r = malloc(MAX_URL_LENGTH);

    // Iterate over the input URL
    while (*p)
    {
        // Convert non-alphanumeric characters to lowercase
        if (!isalnum(*p))
        {
            *q = tolower(*p);
            q++;
        }
        else
        {
            *q = *p;
            q++;
        }

        p++;
    }

    // Null-terminate the sanitized URL
    *q = NULL;

    return r;
}

int main()
{
    char *url = "This is a sample URL with special characters!$$%^&*()";
    char *sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}