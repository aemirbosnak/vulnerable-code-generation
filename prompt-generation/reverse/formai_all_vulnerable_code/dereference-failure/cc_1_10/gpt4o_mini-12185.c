//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

void sanitize_url(const char *input_url, char *sanitized_url) {
    int j = 0;
    
    // Iterate over the original URL character by character
    for (int i = 0; i < strlen(input_url) && j < MAX_URL_LENGTH - 1; i++) {
        char current_char = input_url[i];

        // Check if character is allowed
        if (strchr(ALLOWED_CHARS, current_char) != NULL) {
            sanitized_url[j++] = current_char;
        } else {
            // If not allowed, we can either skip or encode (for simplicity, we skip)
            printf("Skipping invalid character: %c\n", current_char);
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

void print_usage() {
    printf("Usage: url_sanitizer <url_to_sanitize>\n");
    printf("Please provide a valid URL to sanitize.\n");
}

int main(int argc, char *argv[]) {
    char input_url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    // Ensure the program is called with a URL argument
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Copy the input URL from the command line argument
    strncpy(input_url, argv[1], MAX_URL_LENGTH - 1);
    input_url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    printf("Original URL: %s\n", input_url);

    // Sanitize the input URL
    sanitize_url(input_url, sanitized_url);

    // Display the sanitized result
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}