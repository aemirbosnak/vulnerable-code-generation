//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: scientific
/*
 * URL Sanitizer
 *
 * This program sanitizes a given URL by removing potentially
 * harmful characters. The sanitization process is based on the
 * recommendations of the World Wide Web Consortium (W3C) and
 * the Internet Engineering Task Force (IETF).
 *
 * The program takes a single URL as input and prints the sanitized
 * URL to the standard output.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The following characters are considered harmful and will be removed
 * from the URL.
 */
static const char *harmful_chars = "<>\"' ";

/*
 * Sanitize the given URL.
 *
 * @param url The URL to be sanitized.
 * @return The sanitized URL.
 */
static char *sanitize_url(const char *url) {
    char *sanitized_url = NULL;
    size_t sanitized_url_len = 0;

    // Allocate memory for the sanitized URL.
    sanitized_url = malloc(strlen(url) + 1);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for sanitized URL.\n");
        return NULL;
    }

    // Copy the URL to the sanitized URL.
    strcpy(sanitized_url, url);

    // Sanitize the URL.
    for (size_t i = 0; i < strlen(sanitized_url); i++) {
        for (size_t j = 0; j < strlen(harmful_chars); j++) {
            if (sanitized_url[i] == harmful_chars[j]) {
                // Replace the harmful character with a space.
                sanitized_url[i] = ' ';
            }
        }
    }

    // Remove any leading or trailing spaces from the sanitized URL.
    sanitized_url_len = strlen(sanitized_url);
    while (sanitized_url_len > 0 && sanitized_url[sanitized_url_len - 1] == ' ') {
        sanitized_url_len--;
    }
    sanitized_url[sanitized_url_len] = '\0';

    // Return the sanitized URL.
    return sanitized_url;
}

/*
 * Print the usage message.
 */
static void usage(void) {
    fprintf(stderr, "Usage: url_sanitizer <url>\n");
    fprintf(stderr, "Example: url_sanitizer http://www.example.com/\n");
}

/*
 * Main function.
 */
int main(int argc, char **argv) {
    char *url = NULL;
    char *sanitized_url = NULL;

    // Check the number of arguments.
    if (argc != 2) {
        usage();
        return EXIT_FAILURE;
    }

    // Get the URL from the command line.
    url = argv[1];

    // Sanitize the URL.
    sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        return EXIT_FAILURE;
    }

    // Print the sanitized URL.
    printf("%s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL.
    free(sanitized_url);

    return EXIT_SUCCESS;
}