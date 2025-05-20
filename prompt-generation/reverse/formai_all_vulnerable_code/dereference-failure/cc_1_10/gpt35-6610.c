//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function prototypes */
void sanitizeUrl(char *);
int hasInvalidChars(char *);
int isWhitespace(char);

/**
 * Main function
 */
int main() {
    char url[100];

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);

    sanitizeUrl(url);

    printf("Sanitized URL: %s", url);

    return 0;
}

/**
 * Sanitizes a given URL by removing invalid characters and leading/trailing whitespace
 */
void sanitizeUrl(char *url) {
    // Remove leading whitespace
    while (isWhitespace(*url)) {
        url++;
    }

    // Remove trailing whitespace
    char *end = url + strlen(url) - 1;
    while (isWhitespace(*end)) {
        *end-- = '\0';
    }

    // Check for invalid characters
    if (hasInvalidChars(url)) {
        printf("Error: URL contains invalid characters\n");
        exit(EXIT_FAILURE);
    }

    // All characters are valid, no need for further sanitization
}

/**
 * Returns true if the given URL contains any invalid characters
 */
int hasInvalidChars(char *url) {
    while (*url != '\0') {
        if (!isalnum(*url) && *url != '.' && *url != '/' && *url != ':' && *url != '-') {
            return 1;
        }

        url++;
    }

    return 0;
}

/**
 * Returns true if the given character is whitespace
 */
int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}