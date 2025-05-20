//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2083
#define MAX_SANITIZED_LENGTH 2083

typedef struct {
    char original[MAX_URL_LENGTH];
    char sanitized[MAX_SANITIZED_LENGTH];
} Url;

void display_usage() {
    printf("Usage: url_sanitizer <URL>\n");
    printf("This program sanitizes the input URL by escaping invalid characters.\n");
}

void init_url(Url* url) {
    memset(url->original, 0, sizeof(url->original));
    memset(url->sanitized, 0, sizeof(url->sanitized));
}

int is_valid_url_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~');
}

void sanitize_url(const char* input, Url* url) {
    int j = 0;

    for (int i = 0; input[i] != '\0' && j < MAX_SANITIZED_LENGTH - 1; i++) {
        if (is_valid_url_char(input[i])) {
            url->sanitized[j++] = input[i];
        } else {
            // Escape the character using hex encoding
            if (j < MAX_SANITIZED_LENGTH - 3) {
                sprintf(url->sanitized + j, "%%%02X", (unsigned char)input[i]);
                j += 3;
            }
        }
    }
    url->sanitized[j] = '\0';
}

int main(int argc, char* argv[]) {
    Url url;
    
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    init_url(&url);
    strncpy(url.original, argv[1], MAX_URL_LENGTH - 1);
    
    sanitize_url(url.original, &url);

    printf("Original URL: %s\n", url.original);
    printf("Sanitized URL: %s\n", url.sanitized);

    return EXIT_SUCCESS;
}