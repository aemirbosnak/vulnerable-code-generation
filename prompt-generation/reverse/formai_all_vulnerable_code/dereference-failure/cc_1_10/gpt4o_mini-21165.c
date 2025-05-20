//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(const char *url, char *sanitized_url) {
    const char *allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;=";
    int j = 0; // Index for sanitized_url

    for (int i = 0; i < strlen(url); i++) {
        if (strchr(allowed_chars, url[i]) != NULL) {
            sanitized_url[j++] = url[i]; // Copy valid characters
        } else {
            // Encode invalid characters
            j += snprintf(&sanitized_url[j], MAX_URL_LENGTH - j, "%%%02X", (unsigned char)url[i]);
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

void print_usage() {
    printf("URL Sanitizer\n");
    printf("Usage: ./url_sanitizer <URL>\n");
    printf("Example: ./url_sanitizer \"http://example.com/search?q=temp@123&sort=asc\"\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    // Check if the URL is too long
    if (strlen(input_url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    // Sanitize the URL
    sanitize_url(input_url, sanitized_url);

    // Output the result
    printf("Original URL:   %s\n", input_url);
    printf("Sanitized URL:  %s\n", sanitized_url);

    return EXIT_SUCCESS;
}