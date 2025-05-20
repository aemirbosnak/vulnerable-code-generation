//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=%"

void sanitize_url(const char *input_url, char *sanitized_url) {
    size_t j = 0;
    for (size_t i = 0; i < strlen(input_url); i++) {
        if (strchr(ALLOWED_CHARACTERS, input_url[i]) != NULL) {
            sanitized_url[j++] = input_url[i];
        } else if (input_url[i] == ' ') {
            // Replace spaces with '%20'
            sanitized_url[j++] = '%';
            snprintf(sanitized_url + j, 2, "20");
            j += 2;  // Move the pointer ahead to account for the added characters
        } else {
            // Encode unsupported characters using percent-encoding
            snprintf(sanitized_url + j, 4, "%%%02X", (unsigned char)input_url[i]);
            j += 3;  // Move the pointer ahead for the 3 added characters (%XX)
        }
    }
    sanitized_url[j] = '\0';  // Null-terminate the sanitized URL
}

int validate_url(const char *url) {
    // URL should start with a valid scheme
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return 0; // Invalid URL: missing scheme
    }
    // You can add more complex validation here as required
    return 1; // Valid URL
}

void display_usage(const char *program_name) {
    printf("Usage: %s <url>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    if (!validate_url(input_url)) {
        fprintf(stderr, "Error: Invalid URL format.\n");
        return EXIT_FAILURE;
    }

    sanitize_url(input_url, sanitized_url);
    
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}