//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

// Function to check if a character is alphanumeric
bool is_alphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

// Function to sanitize a URL
void sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = (char*) calloc(MAX_LENGTH, sizeof(char));
    bool in_query = false; // flag to denote if we are in the query part of the URL

    // Step 1: Remove any trailing white space
    while (url[strlen(url) - 1] == ' ') {
        url[strlen(url) - 1] = '\0';
    }

    // Step 2: Remove any leading white space
    while (*url == ' ') {
        url++;
    }

    // Step 3: Remove any unnecessary periods
    for (i = 0, j = 0; url[i] != '\0'; i++) {
        if (url[i] == '.') {
            if (url[i+1] == '.' || url[i+1] == '/') {
                continue;
            }
        }
        sanitized_url[j++] = url[i];
    }
    sanitized_url[j] = '\0';

    // Step 4: Remove any unnecessary query parameters
    for (i = 0; sanitized_url[i] != '\0'; i++) {
        if (sanitized_url[i] == '?' || sanitized_url[i] == '#') {
            in_query = true;
        }
        if (in_query) {
            if (!is_alphanumeric(sanitized_url[i])) {
                sanitized_url[i] = '\0';
                break;
            }
        }
    }

    // Step 5: Remove any trailing slashes
    for (i = strlen(sanitized_url) - 1; i > 0; i--) {
        if (sanitized_url[i] == '/') {
            sanitized_url[i] = '\0';
        } else {
            break;
        }
    }

    // Step 6: Copy the sanitized URL back into the original URL
    strncpy(url, sanitized_url, MAX_LENGTH);

    // Free dynamically allocated memory
    free(sanitized_url);
}

int main() {
    char url[MAX_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}