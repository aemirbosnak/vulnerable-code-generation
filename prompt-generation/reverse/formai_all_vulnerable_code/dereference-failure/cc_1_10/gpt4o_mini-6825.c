//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define WHITELIST "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;="

void sanitize_url(const char *input, char *output) {
    int i, j = 0;

    // Iterate through each character of the input URL
    for (i = 0; input[i] != '\0'; i++) {
        if (strchr(WHITELIST, input[i]) != NULL) {
            // If character is in the whitelist, append it to the output
            output[j++] = input[i];
        } else {
            // Otherwise, encode it as a percent-encoded format
            unsigned char byte = (unsigned char)input[i];
            j += sprintf(output + j, "%%%02X", byte);
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <URL>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    // Perform input validation
    if (strlen(input_url) >= MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        return EXIT_FAILURE;
    }

    // Sanitize the URL
    sanitize_url(input_url, sanitized_url);

    // Output the sanitized URL
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}