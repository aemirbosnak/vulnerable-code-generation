//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_BUFFER_SIZE 512

// Function prototypes
char *sanitize_url(const char *url);
int is_safe_char(char c);
void print_usage(char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *url = argv[1];
    
    if (strlen(url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    char *sanitized_url = sanitize_url(url);
    if (sanitized_url) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    } else {
        fprintf(stderr, "Error: Failed to sanitize URL.\n");
    }

    return EXIT_SUCCESS;
}

// Function to sanitize the URL
char *sanitize_url(const char *url) {
    size_t len = strlen(url);
    char *sanitized = malloc(SANITIZED_BUFFER_SIZE);
    if (!sanitized) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len && j < SANITIZED_BUFFER_SIZE - 1; i++) {
        if (is_safe_char(url[i])) {
            sanitized[j++] = url[i];
        } else {
            sanitized[j++] = '_'; // Replace unsafe characters with '_'
        }
    }
    
    sanitized[j] = '\0'; // Null terminate the sanitized string
    return sanitized;
}

// Function to determine if a character is safe for a URL
int is_safe_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == ':' || c == '/' || c == '?' || c == '&' || c == '=');
}

// Function to print usage instructions
void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <URL>\n", program_name);
    fprintf(stderr, "Please provide a valid URL to be sanitized.\n");
}