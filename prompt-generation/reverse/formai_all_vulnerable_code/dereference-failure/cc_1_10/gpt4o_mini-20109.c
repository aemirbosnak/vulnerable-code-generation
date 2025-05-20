//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SAFE_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~"

int is_safe_char(char ch) {
    return strchr(SAFE_CHARACTERS, ch) != NULL;
}

void sanitize_url(const char *input_url, char *sanitized_url) {
    int j = 0;
    for (int i = 0; input_url[i] != '\0'; i++) {
        if (is_safe_char(input_url[i])) {
            sanitized_url[j++] = input_url[i];
        } else {
            // Encode unsafe characters in the format %XY
            sprintf(&sanitized_url[j], "%%%02X", (unsigned char)input_url[i]);
            j += 3; // %XY takes up 3 characters
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized string
}

void print_usage() {
    printf("URL Sanitizer\n");
    printf("Usage: url_sanitizer <url>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    if (strlen(input_url) >= MAX_URL_LENGTH) {
        fprintf(stderr, "Error: Input URL is too long.\n");
        return EXIT_FAILURE;
    }

    sanitize_url(input_url, sanitized_url);
    
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}