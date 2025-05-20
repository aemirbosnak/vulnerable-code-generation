//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
void sanitize_url(char *url) {
    char *p = url;
    char *q = url;
    int len = strlen(url);

    // Remove leading and trailing spaces
    while (isspace(*p)) {
        p++;
    }
    while (isspace(*(q - 1))) {
        q--;
        *q = '\0';
    }

    // Remove consecutive dots and slashes
    while (p < q) {
        if (*p == '.' && *(p + 1) == '.') {
            memmove(p, p + 1, q - p - 1);
            len--;
        } else if (*p == '/' && *(p + 1) == '/') {
            memmove(p, p + 1, q - p - 1);
            len--;
        } else {
            p++;
        }
    }

    // Remove trailing slash
    if (q > url + len - 2 && q[-1] == '/' && q[-2]!= ':') {
        q[-1] = '\0';
    }

    // Convert to lowercase
    for (p = url; *p; p++) {
        *p = tolower(*p);
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    // Prompt user for URL
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize URL
    sanitize_url(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}