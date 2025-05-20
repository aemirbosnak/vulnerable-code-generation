//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

void print_usage() {
    printf("Usage: url_sanitizer <url>\n");
    printf("Example: ./url_sanitizer \"https://example.com/path?query=value\"\n");
}

int is_valid_character(char c) {
    return (strchr(ALLOWED_CHARACTERS, c) != NULL) || (c == ' ');
}

void sanitize_url(const char *input, char *output) {
    int j = 0;
    
    for (int i = 0; input[i] != '\0' && j < MAX_URL_LENGTH - 1; i++) {
        if (is_valid_character(input[i])) {
            if (input[i] == ' ') {
                output[j++] = '%';
                output[j++] = '2';
                output[j++] = '0';
            } else {
                output[j++] = input[i];
            }
        } else {
            snprintf(output + j, 4, "%%%02X", (unsigned char)input[i]);
            j += 3; // each escape sequence is 3 characters long
        }
    }
    output[j] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    if (strlen(input_url) >= MAX_URL_LENGTH) {
        fprintf(stderr, "Error: Input URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    sanitize_url(input_url, sanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}