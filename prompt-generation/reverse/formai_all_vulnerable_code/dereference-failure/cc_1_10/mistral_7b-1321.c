//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1024

bool is_alphanumeric(char c) {
    return (isalnum(c) || (c == '.' || c == '-' || c == '_'));
}

char *sanitize_url(const char *url) {
    size_t length = strlen(url);
    char *sanitized = (char *)calloc(length + 1, sizeof(char));
    int i = 0;

    if (sanitized == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (; i < length && i < MAX_URL_LENGTH; ++i) {
        if (is_alphanumeric(url[i])) {
            sanitized[i] = url[i];
        } else if (url[i] == ':' && i < length - 1 && is_alphanumeric(url[i + 1])) {
            sanitized[i] = url[i];
            ++i;
        } else if (url[i] == '?' || url[i] == '#') {
            // Stop sanitizing at the first occurrence of '?' or '#'
            break;
        } else {
            sanitized[i] = '_';
        }
    }

    sanitized[i] = '\0';

    return sanitized;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *sanitized_url = sanitize_url(argv[1]);

    if (sanitized_url == NULL) {
        fprintf(stderr, "Error: Failed to sanitize URL\n");
        return 1;
    }

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    return 0;
}