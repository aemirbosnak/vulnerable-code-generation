//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 256

char* sanitize_url(char* url)
{
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int j = 0;

    // Remove all special characters
    for (; url[i] != '\0'; i++)
    {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '_')
        {
            sanitized_url[j] = url[i];
            j++;
        }
    }

    // Remove all consecutive repeated characters
    for (i = 0; sanitized_url[i] != '\0'; i++)
    {
        int count = 1;
        for (j = i + 1; sanitized_url[j] != '\0' && sanitized_url[i] == sanitized_url[j]; j++)
        {
            count++;
        }

        if (count > 1)
        {
            sanitized_url[i] = '_';
            i++;
        }
    }

    // Add trailing slash if necessary
    if (sanitized_url[strlen(sanitized_url) - 1] != '/')
    {
        sanitized_url[strlen(sanitized_url)] = '/';
    }

    return sanitized_url;
}

int main()
{
    char* url = "This is a sample URL with special characters!#$%^&*()";
    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}