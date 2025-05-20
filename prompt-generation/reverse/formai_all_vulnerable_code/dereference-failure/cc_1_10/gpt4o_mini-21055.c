//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_char(char c) {
    return strchr(ALLOWED_CHARACTERS, c) != NULL;
}

void sanitize_url(const char *url, char *sanitized_url) {
    int j = 0;
    for (int i = 0; url[i] != '\0'; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j++] = url[i];
        } else {
            // Encode invalid characters as percent-encoding
            j += snprintf(sanitized_url + j, MAX_URL_LENGTH - j, "%%%02X", (unsigned char)url[i]);
        }
    }
    sanitized_url[j] = '\0';
}

void print_usage() {
    printf("URL Sanitizer\n");
    printf("Usage: ./url_sanitizer <url>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    to_lowercase(url);
    sanitize_url(url, sanitized_url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}