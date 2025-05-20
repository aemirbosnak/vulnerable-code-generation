//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 4096

static char *sanitize_url(const char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (!sanitized_url) {
        return NULL;
    }

    // Copy the URL into the sanitized buffer
    strncpy(sanitized_url, url, MAX_URL_LENGTH);

    // Replace any invalid characters with underscores
    for (char *ptr = sanitized_url; *ptr != '\0'; ptr++) {
        if (!isalnum(*ptr) && *ptr != '-' && *ptr != '_' && *ptr != '.' && *ptr != ':') {
            *ptr = '_';
        }
    }

    // Ensure that the URL starts with a valid scheme
    if (!strncmp(sanitized_url, "http://", 7) && !strncmp(sanitized_url, "https://", 8)) {
        if (strlen(sanitized_url) > 7) {
            memmove(sanitized_url + 7, sanitized_url + 8, strlen(sanitized_url) - 7);
        }
    } else {
        memmove(sanitized_url, "http://", 7);
    }

    return sanitized_url;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *sanitized_url = sanitize_url(argv[1]);
    if (!sanitized_url) {
        printf("Error: Could not sanitize URL\n");
        return EXIT_FAILURE;
    }

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    return EXIT_SUCCESS;
}