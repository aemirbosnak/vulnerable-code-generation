//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SAFE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;=%"

void print_usage(const char *prog_name) {
    printf("Usage: %s <url>\n", prog_name);
}

int is_safe_char(char c) {
    // Check if character is in the set of safe chars
    return strchr(SAFE_CHARS, c) != NULL;
}

void sanitize_url(const char *input_url, char *sanitized_url) {
    int i, j = 0;
    size_t len = strlen(input_url);

    for (i = 0; i < len && j < MAX_URL_LENGTH - 1; i++) {
        char c = input_url[i];

        if (is_safe_char(c)) {
            sanitized_url[j++] = c; // Copy safe characters
        } else {
            // If character is not safe, encode as %XX
            j += snprintf(sanitized_url + j, MAX_URL_LENGTH - j, "%%%02X", (unsigned char)c);
        }
    }
    sanitized_url[j] = '\0'; // Null terminate sanitized URL
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    if (strlen(input_url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL length exceeds allowed limit of %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    sanitize_url(input_url, sanitized_url);

    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return EXIT_SUCCESS;
}