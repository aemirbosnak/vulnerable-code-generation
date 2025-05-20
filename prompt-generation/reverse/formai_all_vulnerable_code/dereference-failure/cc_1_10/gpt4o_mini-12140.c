//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZE_MODE_STRICT 1
#define SANITIZE_MODE_LOOSE 2

void display_usage() {
    printf("URL Sanitizer Tool\n");
    printf("Usage: url_sanitizer <URL> [mode]\n");
    printf("Mode:\n");
    printf("  1: Strict (default) - Whitelist specific characters.\n");
    printf("  2: Loose - Allow a broader set of characters.\n");
}

int is_valid_char(char c, int mode) {
    if (mode == SANITIZE_MODE_STRICT) {
        return (isalnum(c) || c == '.' || c == '/' || c == ':' || c == '-' || c == '_' || c == '~');
    } else if (mode == SANITIZE_MODE_LOOSE) {
        return (isalnum(c) || ispunct(c));
    }
    return 0;
}

void sanitize_url(const char *input_url, char *sanitized_url, int mode) {
    int j = 0; 
    for (int i = 0; input_url[i] != '\0' && i < MAX_URL_LENGTH; i++) {
        if (is_valid_char(input_url[i], mode)) {
            sanitized_url[j++] = input_url[i];
        }
    }
    sanitized_url[j] = '\0'; 
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        display_usage();
        return 1;
    }

    char *input_url = argv[1];
    int sanitize_mode = SANITIZE_MODE_STRICT;

    if (argc == 3) {
        sanitize_mode = atoi(argv[2]);
        if (sanitize_mode != SANITIZE_MODE_STRICT && sanitize_mode != SANITIZE_MODE_LOOSE) {
            printf("Invalid mode specified. Please use 1 for strict mode or 2 for loose mode.\n");
            return 1;
        }
    }

    if (strlen(input_url) >= MAX_URL_LENGTH) {
        printf("Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return 1;
    }

    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    sanitize_url(input_url, sanitized_url, sanitize_mode);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}