//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SAFE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

/* A structure to hold the URL and its sanitized version */
typedef struct {
    char original[MAX_URL_LENGTH];
    char sanitized[MAX_URL_LENGTH];
} URL;

/* Function declarations */
int is_safe_char(char c);
void sanitize_url(URL *url);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    // Handle command-line argument
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize URL structure
    URL url;
    strncpy(url.original, argv[1], MAX_URL_LENGTH - 1);
    url.original[MAX_URL_LENGTH - 1] = '\0'; // Ensure null-termination
    url.sanitized[0] = '\0'; // Initialize sanitized string

    // Sanitize the provided URL
    sanitize_url(&url);
    
    // Output the results
    printf("Original URL:  %s\n", url.original);
    printf("Sanitized URL: %s\n", url.sanitized);

    return EXIT_SUCCESS;
}

/* Function to check if a character is allowed in a URL */
int is_safe_char(char c) {
    return strchr(SAFE_CHARS, c) != NULL;
}

/* Function to sanitize a URL by removing unsafe characters and encoding them */
void sanitize_url(URL *url) {
    size_t j = 0;
    for (size_t i = 0; url->original[i] != '\0' && j < MAX_URL_LENGTH - 1; i++) {
        char c = url->original[i];

        // If the character is safe, simply copy it
        if (is_safe_char(c)) {
            url->sanitized[j++] = c;
        } else {
            // Otherwise, encode the unsafe character as %HH format
            // Where HH is the hexadecimal representation of the character
            j += snprintf(url->sanitized + j, MAX_URL_LENGTH - j, "%%%02X", (unsigned char)c);
        }
    }
    url->sanitized[j] = '\0'; // Null-terminate the sanitized URL
}

/* Function to print usage of the program */
void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <url>\n", program_name);
    fprintf(stderr, "Sanitizes the input URL by encoding unsafe characters.\n");
}