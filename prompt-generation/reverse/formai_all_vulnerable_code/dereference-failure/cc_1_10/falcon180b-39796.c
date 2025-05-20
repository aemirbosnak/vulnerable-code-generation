//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 4096

int is_valid_url_char(char c)
{
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%')
        return 1;

    return 0;
}

int is_valid_url(char* url)
{
    int i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH)
    {
        if (!is_valid_url_char(url[i]))
            return 0;
        i++;
    }

    return 1;
}

char* sanitize_url(char* url)
{
    int i = 0, j = 0;
    char* sanitized_url = (char*)malloc(MAX_URL_LENGTH * sizeof(char));

    while (url[i]!= '\0' && i < MAX_URL_LENGTH)
    {
        if (is_valid_url_char(url[i]))
        {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }

    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main()
{
    char* url = "https://www.example.com/path/to/file?query=string&param=value#fragment";
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}