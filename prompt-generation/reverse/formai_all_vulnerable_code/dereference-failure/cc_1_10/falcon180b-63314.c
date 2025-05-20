//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_SCHEMES "http:// https:// ftp://"

int is_allowed_scheme(const char *scheme) {
    const char *allowed_schemes = ALLOWED_SCHEMES;
    while (*allowed_schemes) {
        if (strcmp(scheme, allowed_schemes) == 0) {
            return 1;
        }
        allowed_schemes++;
    }
    return 0;
}

int is_valid_url(const char *url) {
    if (strlen(url) > MAX_URL_LENGTH) {
        return 0;
    }
    char *scheme = strtok(url, "://");
    if (!scheme ||!is_allowed_scheme(scheme)) {
        return 0;
    }
    char *host = strtok(NULL, "/");
    if (!host) {
        return 0;
    }
    char *path = strtok(NULL, "?");
    if (!path) {
        return 0;
    }
    return 1;
}

char *sanitize_url(const char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH + 1);
    memset(sanitized_url, 0, MAX_URL_LENGTH + 1);
    if (!is_valid_url(url)) {
        strncpy(sanitized_url, "Invalid URL", MAX_URL_LENGTH);
        return sanitized_url;
    }
    strncpy(sanitized_url, url, MAX_URL_LENGTH);
    return sanitized_url;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}