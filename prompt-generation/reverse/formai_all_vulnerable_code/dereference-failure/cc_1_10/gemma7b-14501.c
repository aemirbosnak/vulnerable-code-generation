//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

char *sanitize_url(char *url)
{
    char *new_url = malloc(MAX_URL_LENGTH);
    int i = 0, j = 0, valid = 0;

    for (; url[i] != '\0'; i++)
    {
        if (!valid && url[i] == '/')
        {
            valid = 1;
            new_url[j] = '/';
            j++;
        }

        if (valid)
        {
            if (isalnum(url[i]) || url[i] == '-' || url[i] == '_')
            {
                new_url[j] = url[i];
                j++;
            }
            else if (url[i] == ' ')
            {
                new_url[j] = '_';
                j++;
            }
        }
    }

    new_url[j] = '\0';

    return new_url;
}

int main()
{
    char *url = "This is a URL with special characters!^&*()_+-";
    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}