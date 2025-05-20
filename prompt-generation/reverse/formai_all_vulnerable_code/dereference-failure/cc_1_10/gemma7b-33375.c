//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

char *sanitize_url(char *url)
{
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0, j = 0;

    // Normalize the URL by converting all uppercase letters to lowercase
    for (i = 0; url[i] != '\0'; i++)
    {
        url[i] = tolower(url[i]);
    }

    // Remove all special characters from the URL
    for (i = 0; url[i] != '\0'; i++)
    {
        if (!isalnum(url[i]) && url[i] != '-' && url[i] != '_')
        {
            url[i] = '_';
        }
    }

    // Remove duplicate underscores
    for (i = 0; url[i] != '\0'; i++)
    {
        for (j = i + 1; url[j] != '\0' && url[i] == url[j]; j++)
        {
            url[j] = '\0';
        }
    }

    // Copy the sanitized URL to the new memory location
    strcpy(sanitized_url, url);

    // Free the memory allocated for the original URL
    free(url);

    return sanitized_url;
}

int main()
{
    char *url = "This is a sample URL with special characters!#$%&*()_+-";
    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}