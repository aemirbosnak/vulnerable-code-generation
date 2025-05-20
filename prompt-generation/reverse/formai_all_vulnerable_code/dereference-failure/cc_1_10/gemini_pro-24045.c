//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

// Define the regular expression pattern for a valid URL
#define URL_PATTERN "^(https?://)?(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{1,256}\\.[a-zA-Z0-9()]{1,6}\\b([-a-zA-Z0-9()@:%_\\+.~#?&//=]*)"

// Custom error handling function
void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

// Function to sanitize a URL
char *sanitize_url(const char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = (char *)malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        error("Error allocating memory for sanitized URL.");
    }

    // Copy the original URL into the sanitized URL
    strcpy(sanitized_url, url);

    // Create a regular expression object
    regex_t regex;
    if (regcomp(&regex, URL_PATTERN, REG_EXTENDED | REG_NOSUB) != 0) {
        error("Error compiling regular expression.");
    }

    // Match the URL against the regular expression
    int status = regexec(&regex, sanitized_url, 0, NULL, 0);
    if (status != 0) {
        // The URL does not match the valid pattern, so sanitize it
        char *tmp_url = sanitized_url;
        while (*tmp_url != '\0') {
            if (!isalnum(*tmp_url) && *tmp_url != '.' && *tmp_url != '/' && *tmp_url != ':') {
                *tmp_url = '_';
            }
            tmp_url++;
        }
    }

    // Free the regular expression object
    regfree(&regex);

    // Return the sanitized URL
    return sanitized_url;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a URL
    if (argc < 2) {
        error("Error: No URL provided.");
    }

    // Get the URL from the user
    char *url = argv[1];

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the sanitized URL
    free(sanitized_url);

    return 0;
}