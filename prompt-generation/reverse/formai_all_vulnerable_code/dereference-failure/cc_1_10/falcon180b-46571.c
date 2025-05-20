//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 4096

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int sanitized_url_length = 0;

    // Copy the original URL to the sanitized URL
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        // Check if the character is valid in a URL
        if (is_valid_url_char(c)) {
            // Convert the character to lowercase
            c = tolower(c);

            // Append the character to the sanitized URL
            sanitized_url[sanitized_url_length++] = c;
        }
    }

    // Terminate the sanitized URL
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char* input_url = "https://www.example.com/path/to/file?query=string#fragment";
    char* sanitized_url = sanitize_url(input_url);

    printf("Input URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}