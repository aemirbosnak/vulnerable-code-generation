//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
char *sanitize_url(const char* url);

int main()
{
    // sample urls for testing
    const char *url1 = "https://www.example.com/hey/there?foo=bar";
    const char *url2 = "https://www.example.com/my%20dir?file=hello%20world";
    const char *url3 = "http://example.com:80/";

    // calling sanitizer function
    char *sanitized_url1 = sanitize_url(url1);
    char *sanitized_url2 = sanitize_url(url2);
    char *sanitized_url3 = sanitize_url(url3);

    // displaying sanitized urls
    printf("Sanitized URL 1: %s\n", sanitized_url1);
    printf("Sanitized URL 2: %s\n", sanitized_url2);
    printf("Sanitized URL 3: %s\n", sanitized_url3);

    // releasing memory
    free(sanitized_url1);
    free(sanitized_url2);
    free(sanitized_url3);

    return 0;
}

// function to sanitize url
char *sanitize_url(const char* url)
{
    // allocating memory for sanitized url
    char *sanitized_url = (char*)malloc(strlen(url) + 1);
    int i, j;

    // loop to sanitize url
    for(i = 0, j = 0; url[i]; i++, j++)
    {
        // replacing spaces with %20
        if(url[i] == ' ')
        {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j] = '0';
        }
        // skipping interactive elements
        else if(url[i] == '?' || url[i] == '#')
        {
            sanitized_url[j] = url[i];
            break;
        }
        // copying other characters
        else
            sanitized_url[j] = url[i];
    }

    // adding null character at the end
    sanitized_url[j] = '\0';

    return sanitized_url;
}