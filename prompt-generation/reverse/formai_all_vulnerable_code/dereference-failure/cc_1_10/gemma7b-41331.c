//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

char *sanitize_url(char *url)
{
    char *safe_url = malloc(MAX_URL_LENGTH);
    int i = 0, j = 0, flag = 0;

    // Remove all special characters
    for (i = 0; url[i] != '\0'; i++)
    {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '-' || url[i] == '_')
        {
            safe_url[j] = url[i];
            j++;
        }
    }

    // Remove duplicate slashes
    for (i = 0; safe_url[i] != '\0'; i++)
    {
        if (safe_url[i] == '/' && safe_url[i - 1] == '/')
        {
            safe_url[i] = '\0';
            i--;
        }
    }

    // Add the trailing slash if necessary
    if (safe_url[j - 1] != '/')
    {
        safe_url[j] = '/';
        j++;
    }

    safe_url[j] = '\0';
    return safe_url;
}

int main()
{
    char *url = "This is a sample URL with special characters!$/&*()";
    char *safe_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Safe URL: %s\n", safe_url);

    free(safe_url);
    return 0;
}