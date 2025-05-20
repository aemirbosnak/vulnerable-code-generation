//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define SANITIZED_URL_LENGTH 2048

// Function to check if a character is safe to include in a URL
int is_safe_url_char(char c) {
    return isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == ':' || 
           c == '/' || c == '?' || c == '#' || c == '&' || c == '=' || c == '%' || 
           c == '+' || c == ';' || c == '@';
}

// Function to percent-encode unsafe characters in the URL
void percent_encode(char c, char *output) {
    sprintf(output, "%%%02X", (unsigned char)c);
}

// Function to sanitize the input URL
void sanitize_url(const char *input_url, char *sanitized_url) {
    int j = 0; // Index for sanitized URL
    for (int i = 0; i < strlen(input_url); i++) {
        if (is_safe_url_char(input_url[i])) {
            sanitized_url[j++] = input_url[i];
        } else {
            // Percent-encode unsafe character
            char encoded[4];
            percent_encode(input_url[i], encoded);
            strcpy(&sanitized_url[j], encoded);
            j += 3; // Move past the encoded characters
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the string
}

int main() {
    char input_url[MAX_URL_LENGTH];
    char sanitized_url[SANITIZED_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    if (fgets(input_url, sizeof(input_url), stdin) != NULL) {
        // Remove trailing newline from input
        size_t len = strlen(input_url);
        if (len > 0 && input_url[len - 1] == '\n') {
            input_url[len - 1] = '\0';
        }

        // Sanitize the input URL
        sanitize_url(input_url, sanitized_url);

        // Output the sanitized URL
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Input error. Please try again.\n");
    }

    return 0;
}