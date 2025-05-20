//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define WHITELIST "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

// Function declarations
void sanitize_url(const char *url, char *sanitized_url);
int is_valid_character(char c);
void append_character(char *result, char c, int *index);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    char sanitized_url[MAX_URL_LENGTH] = {0};

    if (strlen(url) > MAX_URL_LENGTH - 1) {
        fprintf(stderr, "Error: URL is too long.\n");
        return EXIT_FAILURE;
    }

    sanitize_url(url, sanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return EXIT_SUCCESS;
}

// Function to display usage information
void print_usage() {
    printf("Usage: ./url_sanitizer <url>\n");
    printf("Sanitizes a given URL by removing unsafe characters.\n");
}

// Function to sanitize the URL
void sanitize_url(const char *url, char *sanitized_url) {
    int index = 0;
    size_t length = strlen(url);
    
    for (size_t i = 0; i < length; i++) {
        char current_char = url[i];
        if (is_valid_character(current_char)) {
            append_character(sanitized_url, current_char, &index);
        } else {
            // If the character is not valid, we'll replace it with a placeholder
            append_character(sanitized_url, '?', &index);
        }
    }
    sanitized_url[index] = '\0'; // Null-terminate the sanitized URL
}

// Function to check if a character is valid in a URL
int is_valid_character(char c) {
    return strchr(WHITELIST, c) != NULL || isspace(c);
}

// Function to append a character to the result string
void append_character(char *result, char c, int *index) {
    if (*index < MAX_URL_LENGTH - 1) {
        result[*index] = c;
        (*index)++;
    }
}

// An additional function to further sanitize URLs if needed (could handle remarks)
void further_sanitize_url(const char *url, char *sanitized_url) {
    int index = 0;
    size_t length = strlen(url);

    for (size_t i = 0; i < length; i++) {
        char current_char = url[i];

        if (is_valid_character(current_char)) {
            append_character(sanitized_url, current_char, &index);
        } else {
            // Potentially replace with a safe representation (like %XX encoding)
            snprintf(sanitized_url + index, MAX_URL_LENGTH - index, "%%%02X", (unsigned char)current_char);
            index += 3; // Jump over the three-character '%XX'
        }
    }
    sanitized_url[index] = '\0'; // Null-terminate the sanitized URL
}

// Alternative dynamic allocation for sanitization directly in action.
char* dynamic_sanitize_url(const char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if (!sanitized_url) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    sanitize_url(url, sanitized_url);
    return sanitized_url;
}