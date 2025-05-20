//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
char *sanitize_url(const char *url);

// Helper function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || 
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || 
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || 
            c == '#' || c == '[' || c == ']' || c == '%');
}

// Function to sanitize a URL by escaping invalid characters
char *sanitize_url(const char *url) {
    size_t len = strlen(url);
    char *sanitized = (char *)malloc(len * 3 + 1); // Allocate worst-case size
    char *out = sanitized;

    if (!sanitized) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < len; i++) {
        char c = url[i];
        if (is_valid_url_char(c)) {
            *out++ = c;
        } else {
            // Convert invalid character to %HH format
            out += sprintf(out, "%%%02X", (unsigned char)c);
        }
    }
    
    *out = '\0'; // Null-terminate the string

    return sanitized;
}

// Main function to demonstrate URL sanitization
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char *sanitized_url = sanitize_url(input_url);

    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url); // Free allocated memory
    return EXIT_SUCCESS;
}