//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

void print_usage() {
    printf("Usage: url_sanitizer <url>\n");
    printf("Sanitizes a URL by removing illegal characters.\n");
}

bool is_char_allowed(char c) {
    return strchr(ALLOWED_CHARSET, c) != NULL;
}

void sanitize_url(const char* input_url, char* sanitized_url) {
    int j = 0;
    for (int i = 0; input_url[i] != '\0' && i < MAX_URL_LENGTH; ++i) {
        if (is_char_allowed(input_url[i])) {
            sanitized_url[j++] = input_url[i];
        } else {
            printf("Whoa! Illegal character '%c' found and scrubbed out!\n", input_url[i]);
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE; 
    }

    char *input_url = argv[1];

    if (strlen(input_url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Shocking! Your URL exceeds the maximum allowed length of %d characters!\n", MAX_URL_LENGTH);
        return EXIT_FAILURE; 
    }

    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(input_url, sanitized_url);

    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS; 
}