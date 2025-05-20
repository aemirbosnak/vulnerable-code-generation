//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

/* Function prototypes */
int count_valid_chars(const char* str);
void sanitize_url(char* url);

int main()
{
    char url[MAX_URL_LENGTH];

    /* Request input URL from user */
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    /* Remove trailing newline from URL */
    url[strcspn(url, "\n")] = 0;

    /* Sanitize the URL */
    sanitize_url(url);

    /* Print the sanitized URL */
    printf("Sanitized URL: %s\n", url);

    return 0;
}

/* Count the number of valid characters in a string */
int count_valid_chars(const char* str)
{
    int count = 0;
    const char* p = str;

    while (*p != '\0')
    {
        /* Only count valid characters: alphanumeric, hyphen, dot, and slash */
        if (isalnum(*p) || *p == '-' || *p == '.' || *p == '/')
        {
            count++;
        }
        p++;
    }

    return count;
}

/* Sanitize a URL by removing invalid characters */
void sanitize_url(char* url)
{
    char* p = url;
    char* q = url;

    /* Remove any leading whitespace */
    while (isspace(*p))
    {
        p++;
    }

    /* Copy over valid characters */
    while (*p != '\0')
    {
        /* Only copy valid characters */
        if (isalnum(*p) || *p == '-' || *p == '.' || *p == '/')
        {
            *q++ = *p++;
        }
        else
        {
            p++;
        }
    }

    /* Remove any trailing whitespace */
    while (q > url && isspace(*(q-1)))
    {
        q--;
    }

    /* Terminate the sanitized URL string */
    *q = '\0';

    /* Reallocate the string to the correct size */
    char* new_url = realloc(url, count_valid_chars(url) + 1);
    if (new_url != NULL)
    {
        url = new_url;
    }
}