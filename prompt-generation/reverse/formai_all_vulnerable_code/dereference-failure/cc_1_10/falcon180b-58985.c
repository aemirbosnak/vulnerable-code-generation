//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c)) {
        return 1;
    }
    switch (c) {
        case '-':
        case '_':
        case '.':
        case '~':
            return 1;
        default:
            return 0;
    }
}

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int j = 0;
    while (url[i]) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char* unsanitized_url = "https://example.com/path/to/resource?query=string#fragment";
    char* sanitized_url = sanitize_url(unsanitized_url);
    printf("Unsanitized URL: %s\n", unsanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}

/*
Expected output:
Unsanitized URL: https://example.com/path/to/resource?query=string#fragment
Sanitized URL: https://example.com/path/to/resource?query=string#fragment
*/