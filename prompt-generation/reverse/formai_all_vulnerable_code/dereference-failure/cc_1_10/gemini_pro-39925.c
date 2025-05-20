//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the maximum length of a sanitized URL
#define MAX_SANITIZED_URL_LENGTH 2048

// Define the list of unsafe characters that need to be escaped
char *unsafe_chars = "%<>\"'&";

// Function to escape unsafe characters in a URL
char *escape_url(char *url) {
    char *sanitized_url = malloc(MAX_SANITIZED_URL_LENGTH);
    int i, j;
    for (i = 0, j = 0; url[i] != '\0'; i++) {
        char c = url[i];
        if (strchr(unsafe_chars, c) != NULL) {
            sprintf(sanitized_url + j, "%%%02X", c);
            j += 3;
        } else {
            sanitized_url[j++] = c;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
    char *escaped_url = escape_url(url);
    char *sanitized_url = malloc(MAX_SANITIZED_URL_LENGTH);
    int i, j;
    for (i = 0, j = 0; escaped_url[i] != '\0'; i++) {
        char c = escaped_url[i];
        if (c == '%') {
            if (escaped_url[i + 1] != '\0' && escaped_url[i + 2] != '\0') {
                char hex[3];
                hex[0] = escaped_url[i + 1];
                hex[1] = escaped_url[i + 2];
                hex[2] = '\0';
                int code = strtol(hex, NULL, 16);
                if (code >= 0 && code <= 255) {
                    sanitized_url[j++] = (char)code;
                    i += 2;
                } else {
                    sanitized_url[j++] = c;
                }
            } else {
                sanitized_url[j++] = c;
            }
        } else {
            sanitized_url[j++] = c;
        }
    }
    sanitized_url[j] = '\0';
    free(escaped_url);
    return sanitized_url;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return EXIT_SUCCESS;
}