//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of banned characters for URLs
char *banned_chars = "<>&\"'";

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        perror("malloc");
        return NULL;
    }

    // Copy the URL into the sanitized URL
    strcpy(sanitized_url, url);

    // Iterate over the characters in the sanitized URL
    for (char *c = sanitized_url; *c != '\0'; c++) {
        // If the character is banned, replace it with an underscore
        if (strchr(banned_chars, *c) != NULL) {
            *c = '_';
        }
    }

    // Return the sanitized URL
    return sanitized_url;
}

int main(int argc, char **argv) {
    // Check if the user provided a URL
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Sanitize the URL
    char *sanitized_url = sanitize_url(argv[1]);
    if (sanitized_url == NULL) {
        return EXIT_FAILURE;
    }

    // Print the sanitized URL
    printf("%s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return EXIT_SUCCESS;
}