//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/"

void print_usage(const char *program_name) {
    printf("Usage: %s <url>\n", program_name);
    printf("Example: %s \"http://example.com/test?param=value\"\n", program_name);
}

int is_valid_char(char c) {
    return strchr(ALLOWED_CHARS, c) != NULL;
}

void sanitize_url(const char *url, char *sanitized_url) {
    size_t j = 0;
    for (size_t i = 0; url[i] != '\0'; i++) {
        if (is_valid_char(url[i])) {
            sanitized_url[j++] = url[i];
        } else {
            // Replace invalid characters with a safe substitution
            snprintf(&sanitized_url[j], 4, "%%%02X", (unsigned char)url[i]);
            j += 3; // Increment by 3 for the %XX format
        }
    }
    sanitized_url[j] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *input_url = argv[1];
    
    // Allocate buffer for sanitized URL
    char *sanitized_url = (char *)malloc(BUFFER_SIZE);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Sanitize URL
    sanitize_url(input_url, sanitized_url);

    // Output result
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    // Cleanup
    free(sanitized_url);
    return EXIT_SUCCESS;
}