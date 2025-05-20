//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH 4096

// Function prototypes
bool is_valid_char(char c);
void sanitize_url(const char *input_url, char *sanitized_url);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    // Check the number of command line arguments
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize variables
    const char *input_url = argv[1];
    char sanitized_url[SANITIZED_URL_LENGTH];

    // Sanitize the URL
    sanitize_url(input_url, sanitized_url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}

void sanitize_url(const char *input_url, char *sanitized_url) {
    // Check if the input URL length is greater than the maximum allowed length
    if (strlen(input_url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: Input URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        exit(EXIT_FAILURE);
    }

    // Loop through each character in the input URL
    int j = 0; // Index for sanitized URL
    for (int i = 0; input_url[i] != '\0' && j < SANITIZED_URL_LENGTH - 1; i++) {
        char c = input_url[i];

        // If the character is valid, copy it to the sanitized URL buffer
        if (is_valid_char(c)) {
            sanitized_url[j++] = c;
        } else {
            // Replace invalid characters with an underscore
            sanitized_url[j++] = '_';
        }
    }
    
    // Null-terminate the sanitized URL
    sanitized_url[j] = '\0';
}

bool is_valid_char(char c) {
    // Define valid characters for a URL
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' ||
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' ||
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' ||
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' ||
            c == '#' || c == '[' || c == ']' || c == '%');
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <url>\n", program_name);
    fprintf(stderr, "Sanitize the given URL by replacing invalid characters with underscores.\n");
}