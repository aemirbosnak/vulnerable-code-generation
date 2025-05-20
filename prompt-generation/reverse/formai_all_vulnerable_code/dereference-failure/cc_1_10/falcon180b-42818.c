//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
bool is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~') {
        return true;
    }
    return false;
}

// Function to sanitize a URL by removing any invalid characters and encoding special characters
char* sanitize_url(const char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    strncpy(sanitized_url, url, MAX_URL_LENGTH);

    char* p = sanitized_url;
    while (*p) {
        if (!is_valid_url_char(*p)) {
            *p = '%';
            p++;
            sprintf(p, "%02X", *url);
            url++;
        } else {
            p++;
        }
    }

    return sanitized_url;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    return 0;
}