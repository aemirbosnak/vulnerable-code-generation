//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~'
            || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')'
            || c == ';' || c == ':' || c == '@' || c == '&' || c == '='
            || c == '+' || c == '$' || c == ',' || c == '/' || c == '?'
            || c == '#' || c == '[' || c == ']' || c == '%');
}

// Function to sanitize a given URL
char* sanitize_url(const char* input_url) {
    size_t len = strlen(input_url);
    char* sanitized_url = (char*)malloc(len + 1);  // Allocate memory
    if (!sanitized_url) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (is_valid_url_char(input_url[i])) {
            sanitized_url[j++] = input_url[i];
        }
    }
    sanitized_url[j] = '\0';  // Null-terminate the string

    return sanitized_url;  // Return the sanitized URL
}

// Function to prompt user input
void get_input_url(char* url_buffer, size_t buffer_size) {
    printf("Enter a URL to sanitize: ");
    // Use fgets for safe input, preventing buffer overflow
    if (fgets(url_buffer, buffer_size, stdin) != NULL) {
        // Remove the new line character if it exists
        url_buffer[strcspn(url_buffer, "\n")] = '\0';
    }
}

int main() {
    const size_t BUFFER_SIZE = 2048;
    char *input_url = (char*)malloc(BUFFER_SIZE);
    
    if (!input_url) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    get_input_url(input_url, BUFFER_SIZE);  // Get URL from user
    char *sanitized_url = sanitize_url(input_url);  // Sanitize the URL

    // Display the original and sanitized URLs
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free allocated memory
    free(input_url);
    free(sanitized_url);

    return EXIT_SUCCESS;
}