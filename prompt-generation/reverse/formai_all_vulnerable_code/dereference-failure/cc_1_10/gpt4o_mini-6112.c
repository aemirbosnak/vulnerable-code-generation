//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH 4096

// Function prototypes
char* sanitize_url(const char* url);
int is_valid_url_char(char c);
void print_usage(const char* program_name);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char* original_url = argv[1];
    
    // Sanitize the URL
    char* sanitized_url = sanitize_url(original_url);

    // Output the sanitized URL
    if(sanitized_url != NULL) {
        printf("Original URL: %s\n", original_url);
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    } else {
        printf("Error sanitizing URL.\n");
    }

    return EXIT_SUCCESS;
}

// Function to sanitize a URL
char* sanitize_url(const char* url) {
    if (strlen(url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return NULL;
    }

    char* sanitized = (char*)malloc(SANITIZED_URL_LENGTH);
    if (!sanitized) {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }

    size_t j = 0; // Index for sanitized string
    for (size_t i = 0; url[i] != '\0' && j < SANITIZED_URL_LENGTH - 1; i++) {
        char c = url[i];

        // Check if the character is valid
        if (is_valid_url_char(c)) {
            sanitized[j++] = c;
        } else {
            // Replace non-valid characters with underscore
            sanitized[j++] = '_';
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string

    return sanitized;
}

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    // Define valid characters according to RFC 3986
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || 
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || 
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || 
            c == '#' || c == '[' || c == ']' || c == '@');
}

// Function to print usage instructions
void print_usage(const char* program_name) {
    fprintf(stderr, "Usage: %s <URL>\n", program_name);
    fprintf(stderr, "Sanitizes the input URL by replacing invalid characters with underscores.\n");
}