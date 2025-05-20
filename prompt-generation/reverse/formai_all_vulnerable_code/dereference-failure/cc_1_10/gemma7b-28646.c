//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

typedef struct UrlSanitizer
{
    char *url;
    int length;
    struct UrlSanitizer *next;
} UrlSanitizer;

UrlSanitizer *urlSanitizer_create(char *url)
{
    UrlSanitizer *new_sanitizer = malloc(sizeof(UrlSanitizer));
    new_sanitizer->url = strdup(url);
    new_sanitizer->length = strlen(url);
    new_sanitizer->next = NULL;

    return new_sanitizer;
}

void urlSanitizer_free(UrlSanitizer *sanitizer)
{
    free(sanitizer->url);
    free(sanitizer);
}

void sanitize_url(UrlSanitizer *sanitizer)
{
    char *original_url = sanitizer->url;
    char *new_url = malloc(MAX_URL_LENGTH);

    int i = 0;
    for (i = 0; i < sanitizer->length && original_url[i] != '\0'; i++)
    {
        switch (original_url[i])
        {
            case '(':
            case ')':
            case '/':
            case '*':
            case '"':
            case '\\':
                new_url[i] = '_';
                break;
            default:
                new_url[i] = original_url[i];
                break;
        }
    }

    new_url[i] = '\0';

    free(sanitizer->url);
    sanitizer->url = strdup(new_url);
    sanitizer->length = strlen(new_url);
}

int main()
{
    char *url = "This is a sample url with (special characters) and #special characters!";

    UrlSanitizer *sanitizer = urlSanitizer_create(url);

    sanitize_url(sanitizer);

    printf("Sanitized URL: %s\n", sanitizer->url);

    urlSanitizer_free(sanitizer);

    return 0;
}