//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool has_illegal_chars(const char *url)
{
    // List of illegal characters
    const char *illegal_chars = "<>\'\"\\|`^";
    // Check if url contains any illegal character
    for (int i = 0; i < strlen(illegal_chars); i++)
    {
        if (strchr(url, illegal_chars[i]) != NULL)
        {
            return true;
        }
    }
    return false;
}

char *sanitize_url(const char *url)
{
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0)
    {
        // Invalid URL
        return NULL;
    }

    if (has_illegal_chars(url))
    {
        // URL contains illegal characters
        return NULL;
    }

    // Remove trailing spaces
    char *clean_url = strdup(url);
    int len = strlen(clean_url);
    while (len > 0 && clean_url[len-1] == ' ')
    {
        clean_url[--len] = '\0';
    }

    // Remove any tab or newline characters
    char *pos = clean_url;
    while (*pos != '\0')
    {
        if (*pos == '\t' || *pos == '\n')
        {
            *pos = ' ';
        }
        pos++;
    }

    // Remove any extra spaces
    char *start = clean_url;
    char *end = clean_url;
    bool last_char_space = true;
    while (*end != '\0')
    {
        if (*end == ' ')
        {
            if (!last_char_space)
            {
                *(start++) = ' ';
                last_char_space = true;
            }
        }
        else
        {
            *(start++) = *end;
            last_char_space = false;
        }
        end++;
    }
    *start = '\0';

    return clean_url;
}

int main()
{
    // Testing the sanitizer function
    char *url1 = "http://www.google.com";
    printf("Original URL: %s\n", url1);
    printf("Sanitized URL: %s\n\n", sanitize_url(url1));

    char *url2 = "https://www.abc.net.au/news/2021-09-09/nsw-covid-live-update/100456484";
    printf("Original URL: %s\n", url2);
    printf("Sanitized URL: %s\n\n", sanitize_url(url2));

    char *url3 = "http://www.example.com/<>\\|/:\"*?";
    printf("Original URL: %s\n", url3);
    printf("Sanitized URL: %s\n\n", sanitize_url(url3));

    char *url4 = "ftp://www.example.com";
    printf("Original URL: %s\n", url4);
    printf("Sanitized URL: %s\n\n", sanitize_url(url4));

    return 0;
}