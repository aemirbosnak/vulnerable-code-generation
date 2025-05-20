//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define URL_MAX_SIZE 2048
#define SANITIZED_URL_MAX_SIZE 4096

void sanitize_url(const char *url, char *sanitized_url) {
    size_t j = 0;
    for (size_t i = 0; i < strlen(url); i++) {
        char current_char = url[i];

        // Allow alphanumeric characters and some special characters
        if (isalnum(current_char) || current_char == '-' || current_char == '_' || 
            current_char == '.' || current_char == '~' || current_char == ':' || 
            current_char == '/' || current_char == '?' || current_char == '&' || 
            current_char == '=' || current_char == '#' || current_char == '%' || 
            current_char == '+') {
            sanitized_url[j++] = current_char; // Acceptable char, add to sanitized URL
        } else {
            // Convert the character to its hexadecimal representation
            j += sprintf(sanitized_url + j, "%%%02X", (unsigned char)current_char);
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

void print_usage() {
    printf("Welcome to the URL Sanitizer!\n");
    printf("-----------------------------------\n");
    printf("Usage:\n");
    printf("   ./url_sanitizer <URL>\n");
    printf("   Please provide a URL for sanitization.\n");
    printf("-----------------------------------\n");
}

int main(int argc, char *argv[]) {
    // Check for proper argument count
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    if (strlen(url) > URL_MAX_SIZE) {
        printf("Error: URL is too long! Maximum length is %d characters.\n", URL_MAX_SIZE);
        return EXIT_FAILURE;
    }

    char sanitized_url[SANITIZED_URL_MAX_SIZE];
    sanitize_url(url, sanitized_url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}