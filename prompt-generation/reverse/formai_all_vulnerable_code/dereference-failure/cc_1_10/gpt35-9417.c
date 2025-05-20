//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_URL_LENGTH = 100;

// Function prototype
char* sanitizeUrl(const char* url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize:\n");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;   // Remove the newline character from input if present

    // Sanitize the URL
    char* sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl); // Free the dynamically allocated memory
    return 0;
}

char* sanitizeUrl(const char* url) {
    // Allocate memory for the sanitized URL
    char* sanitizedUrl = (char*) calloc(MAX_URL_LENGTH, sizeof(char));

    int i, j = 0;
    for (i = 0; url[i] != '\0'; i++) {
        if (isalnum(url[i])) {
            // Append alphanumeric characters to the sanitized URL
            sanitizedUrl[j++] = url[i];
        } else if (url[i] == ':') {
            // Append the colon character if it's the first character (protocol)
            if (i == 0) {
                sanitizedUrl[j++] = url[i];
            }
        } else if (url[i] == '.') {
            // Append the dot character if it's not immediately after another dot
            if (url[i-1] != '.') {
                sanitizedUrl[j++] = url[i];
            }
        } else if (url[i] == '/') {
            // Append the slash character if it's not immediately after another slash
            if (url[i-1] != '/') {
                sanitizedUrl[j++] = url[i];
            }
        }
    }

    // Return the sanitized URL
    return sanitizedUrl;
}