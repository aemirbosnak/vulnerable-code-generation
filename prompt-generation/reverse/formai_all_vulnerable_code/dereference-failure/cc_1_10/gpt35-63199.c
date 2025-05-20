//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* sanitizeUrl(char *url);

int main()
{
    char url[100];
    printf("Enter URL to sanitize: ");
    fgets(url, 100, stdin);
    
    char *sanitizedUrl = sanitizeUrl(url);
    printf("\nSanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl);
    
    return 0;
}

char* sanitizeUrl(char *url)
{
    // removing whitespace characters from url
    char *start = url;
    while (isspace(*start)) start++;
    char *end = url + strlen(url) - 1;
    while (isspace(*end)) end--;
    *(end + 1) = '\0';
    int len = (end - start) + 1;
    
    // url starts with http/https and ends with .com
    if (strncmp(start, "http://", 7) == 0 || strncmp(start, "https://", 8) == 0)
    {
        if (strncmp(end - 3, ".com", 4) == 0)
        {
            return strdup(start); // no need to sanitize
        }
        else
        {
            // appending .com to url
            char *sanitized = malloc(len + 5);
            strncpy(sanitized, start, len);
            sanitized[len] = '.';
            sanitized[len + 1] = 'c';
            sanitized[len + 2] = 'o';
            sanitized[len + 3] = 'm';
            sanitized[len + 4] = '\0';
            return sanitized;
        }
    }
    
    // url does not start with http/https
    else
    {
        // appending http:// to url
        char *sanitized = malloc(len + 8);
        strncpy(sanitized, "http://", 7);
        strncpy(sanitized + 7, start, len);
        sanitized[len + 7] = '\0';
        return sanitized;
    }
}