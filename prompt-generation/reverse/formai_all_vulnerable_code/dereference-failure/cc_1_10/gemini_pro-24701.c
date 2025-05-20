//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <curl/curl.h>

#define MAX_URL_LEN 2048

static char* sanitize_url(const char* url) {
    size_t len = strlen(url);
    if (len > MAX_URL_LEN) {
        return NULL;
    }

    char* sanitized_url = malloc(len + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    strcpy(sanitized_url, url);

    for (size_t i = 0; i < len; i++) {
        char c = sanitized_url[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            sanitized_url[i] = '+';
        } else if (c == '%' && i < len - 2) {
            char hex1 = sanitized_url[i + 1];
            char hex2 = sanitized_url[i + 2];
            if (isxdigit(hex1) && isxdigit(hex2)) {
                i += 2;
                continue;
            }
        }
    }

    return sanitized_url;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s URL\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* url = argv[1];
    char* sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Error: URL is too long or contains invalid characters.\n");
        return EXIT_FAILURE;
    }

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return EXIT_SUCCESS;
}