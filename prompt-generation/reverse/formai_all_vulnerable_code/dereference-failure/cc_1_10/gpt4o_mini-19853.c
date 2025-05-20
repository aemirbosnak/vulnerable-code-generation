//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    return (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || 
            c == ':' || c == '/' || c == '?' || c == '#' || c == '[' || 
            c == ']' || c == '@' || c == '!' || c == '$' || c == '&' || 
            c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || 
            c == ',' || c == ';' || c == '=');
}

// Function to sanitize a URL
void sanitize_url(const char *input_url, char *sanitized_url) {
    size_t j = 0;
    for (size_t i = 0; i < strlen(input_url) && j < MAX_URL_LENGTH - 1; i++) {
        if (is_valid_url_char(input_url[i])) {
            sanitized_url[j++] = input_url[i];
        } else {
            // If the character is invalid, encode it as %XX
            snprintf(sanitized_url + j, 4, "%%%02X", (unsigned char)input_url[i]);
            j += 3; // Move the index past the newly added encoded characters
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

// Function to display the sanitized URL
void display_result(const char *input_url) {
    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(input_url, sanitized_url);
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Sanitize and display the URL
    display_result(argv[1]);

    return EXIT_SUCCESS;
}