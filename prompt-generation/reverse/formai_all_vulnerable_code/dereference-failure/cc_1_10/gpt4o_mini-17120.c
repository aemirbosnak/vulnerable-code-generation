//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character.
int is_valid_url_char(char ch) {
    return (isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~' || 
            ch == '/' || ch == '?' || ch == ':' || ch == '@' || 
            ch == '&' || ch == '=' || ch == '+' || ch == '#' || 
            ch == '%' || ch == ';' || ch == ',');
}

// Function to sanitize the URL by removing invalid characters.
void sanitize_url(const char *input_url, char *sanitized_url) {
    int j = 0; // Index for sanitized_url

    // Iterate through each character of the input URL
    for (int i = 0; input_url[i] != '\0'; i++) {
        if (is_valid_url_char(input_url[i])) {
            sanitized_url[j++] = input_url[i]; // Keep valid characters
        } else {
            snprintf(sanitized_url + j, 4, "%%%02X", (unsigned char)input_url[i]);
            j += 3; // Each encoded character takes 3 bytes (e.g., '%20')
        }
    }
    sanitized_url[j] = '\0'; // Null terminate the sanitized URL
}

// Function to display usage instructions
void display_usage() {
    printf("URL Sanitizer\n");
    printf("Usage: ./url_sanitizer <url>\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    // Sanitize the input URL
    sanitize_url(input_url, sanitized_url);

    // Display the sanitized URL
    printf("Original URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}