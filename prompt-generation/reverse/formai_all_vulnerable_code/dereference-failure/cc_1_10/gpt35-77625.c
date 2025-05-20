//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

bool is_ascii_alphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
}

bool is_url_safe_char(char c) {
    return is_ascii_alphanumeric(c) ||
           c == '-' ||
           c == '_' ||
           c == '.' ||
           c == '~';
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH + 1);
    memset(sanitized_url, 0, MAX_URL_LENGTH + 1); // Initialize all characters to null.
    size_t sanitized_url_length = 0;
    size_t url_length = strlen(url);

    for (size_t i = 0; i < url_length; i++) {
        char current_char = url[i];
        if (is_url_safe_char(current_char)) {
            sanitized_url[sanitized_url_length++] = current_char;
            if (sanitized_url_length == MAX_URL_LENGTH) {
                break;
            }
        }
    }
    return sanitized_url;
}

int main(void) {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; // Remove the newline character at the end of the input.

    char *sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}