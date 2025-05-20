//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

typedef struct UrlSanitizer
{
    char* url;
    int length;
    char* sanitized_url;
    int sanitized_length;
} UrlSanitizer;

UrlSanitizer* sanitize_url(char* url)
{
    UrlSanitizer* sanitizer = malloc(sizeof(UrlSanitizer));
    sanitizer->url = strdup(url);
    sanitizer->length = strlen(url);
    sanitizer->sanitized_url = malloc(MAX_URL_LENGTH);
    sanitizer->sanitized_length = 0;

    char* p = sanitizer->url;
    char* end = strchr(p, '?');

    if (end)
    {
        sanitizer->sanitized_length += snprintf(sanitizer->sanitized_url, MAX_URL_LENGTH, "%s?", p);
        p = end + 1;
    }

    if (p)
    {
        sanitizer->sanitized_length += snprintf(sanitizer->sanitized_url + sanitizer->sanitized_length, MAX_URL_LENGTH - sanitizer->sanitized_length, "%s", p);
    }

    return sanitizer;
}

int main()
{
    char* url = "This is a sample URL with some special characters!?!?";
    UrlSanitizer* sanitizer = sanitize_url(url);

    printf("Original URL: %s\n", sanitizer->url);
    printf("Sanitized URL: %s\n", sanitizer->sanitized_url);

    free(sanitizer->url);
    free(sanitizer->sanitized_url);
    free(sanitizer);

    return 0;
}