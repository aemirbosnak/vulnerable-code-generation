//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_url_length = 0;

    // Loop through each character in the URL
    for (int i = 0; i < strlen(url); i++) {
        // Check if the character is valid in a URL
        if (is_valid_url_char(url[i])) {
            // Copy the valid character to the sanitized URL
            sanitized_url[sanitized_url_length] = url[i];
            sanitized_url_length++;
        }
    }

    // Terminate the sanitized URL string
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char* url = "https://example.com/path/to/page?query=string#fragment";
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}