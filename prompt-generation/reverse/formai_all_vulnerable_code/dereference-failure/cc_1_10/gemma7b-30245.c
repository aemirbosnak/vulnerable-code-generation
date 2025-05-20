//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 256

void sanitize_url(char *url)
{
    char *ptr = url;
    char *start = NULL;
    char *end = NULL;

    // Remove leading and trailing spaces
    while (*ptr && isspace(*ptr))
    {
        ptr++;
    }

    // Find the start of the actual URL
    while (*ptr && !isalnum(*ptr))
    {
        ptr++;
    }

    // Find the end of the URL
    end = strchr(ptr, '?');
    if (end)
    {
        *end = '\0';
    }

    // Normalize case and remove special characters
    for (ptr = start; ptr && *ptr; ptr++)
    {
        *ptr = tolower(*ptr);
        if (*ptr == '\\' || *ptr == '/' || *ptr == '*' || *ptr == '"')
        {
            *ptr = '\0';
        }
    }

    // Copy the sanitized URL to the original buffer
    strncpy(url, start, end - start);
}

int main()
{
    char url[MAX_BUFFER_SIZE] = "  /a b c?param=value  ";

    sanitize_url(url);

    printf("%s", url);

    return 0;
}