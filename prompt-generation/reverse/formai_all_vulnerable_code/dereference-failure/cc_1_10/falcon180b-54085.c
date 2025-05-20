//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the given URL
void sanitize_url(char *url) {
    char *p = url;
    char *q = url;
    int len = strlen(url);
    int i = 0;

    // Remove any leading/trailing spaces
    while (isspace(*p)) p++;
    while (isspace(*(q - 1))) q--;
    len -= (q - p);

    // Remove any non-ASCII characters
    while (i < len) {
        if (!isascii(*p)) {
            *p = '_';
        }
        p++;
        i++;
    }

    // Remove any duplicate underscores
    while (i < len) {
        if (*p == '_' && *(p - 1) == '_') {
            *p = '_';
            p++;
            i++;
        } else {
            p++;
            i++;
        }
    }

    // Append a trailing underscore if necessary
    if (i == len) {
        strcat(url, "_");
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get the input URL from the user
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}