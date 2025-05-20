//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;
    int i = 0;

    // Remove leading and trailing spaces
    while (*p && isspace(*p)) {
        p++;
    }
    while (*q && isspace(*q)) {
        q--;
    }

    // Normalize case
    for (p = q; *p; p++) {
        if (isupper(*p)) {
            *p = tolower(*p);
        }
    }

    // Remove invalid characters
    for (p = q; *p; p++) {
        if (!isalnum(*p) && *p != '-' && *p != '_') {
            *p = '\0';
        }
    }

    // Trim unnecessary characters
    while (*q && !isalnum(*q)) {
        *q = '\0';
    }

    // Return sanitized URL
    return;
}

int main()
{
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}