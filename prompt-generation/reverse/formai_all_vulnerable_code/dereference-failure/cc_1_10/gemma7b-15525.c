//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

char *sanitize_url(char *url)
{
    char *normalized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int normalized_url_length = 0;

    // Normalize uppercase letters
    for (; url[i] && normalized_url_length < MAX_URL_LENGTH; i++)
    {
        normalized_url[normalized_url_length++] = tolower(url[i]);
    }

    // Remove invalid characters
    for (; url[i] && normalized_url_length < MAX_URL_LENGTH; i++)
    {
        if (!isalnum(url[i]) && url[i] != '-' && url[i] != '_')
        {
            url[i] = '\0';
        } else
        {
            normalized_url[normalized_url_length++] = url[i];
        }
    }

    // Remove consecutive slashes
    i = 0;
    while (url[i] && url[i + 1] == '/')
    {
        url[i] = '\0';
        i++;
    }

    // Add trailing slash if necessary
    if (!url[normalized_url_length - 1] == '/')
    {
        normalized_url[normalized_url_length++] = '/';
    }

    // Null terminate the normalized URL
    normalized_url[normalized_url_length] = '\0';

    return normalized_url;
}

int main()
{
    char *url = "This is a sample URL with invalid characters and uppercase letters!";
    char *normalized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Normalized URL: %s\n", normalized_url);

    free(normalized_url);

    return 0;
}