//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~"

void print_usage() {
    printf("Usage: url_sanitizer <url>\n");
}

int is_allowed_character(char c) {
    return strchr(ALLOWED_CHARACTERS, c) != NULL;
}

void sanitize_url(const char *input, char *output) {
    int out_index = 0;
    for (int in_index = 0; input[in_index] != '\0' && out_index < MAX_URL_LEN - 1; in_index++) {
        char c = input[in_index];
        if (is_allowed_character(c)) {
            output[out_index++] = c;
        } else if (isspace(c)) {
            output[out_index++] = '_';  // Replacing spaces with underscores
        } else {
            out_index += snprintf(output + out_index, MAX_URL_LEN - out_index, "%%%02X", (unsigned char)c);
        }
    }
    output[out_index] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];

    if (strlen(input_url) > MAX_URL_LEN) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LEN);
        return EXIT_FAILURE;
    }

    char sanitized_url[MAX_URL_LEN];
    sanitize_url(input_url, sanitized_url);

    printf("Sanitized URL: %s\n", sanitized_url);
    return EXIT_SUCCESS;
}