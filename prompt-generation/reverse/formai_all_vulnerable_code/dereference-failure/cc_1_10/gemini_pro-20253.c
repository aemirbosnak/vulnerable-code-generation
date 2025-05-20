//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

// Global variables
char *url;
char *sanitized_url;

// Function to check if a character is valid in a URL
bool is_valid_url_char(char c) {
    // Allowed characters in a URL
    const char *valid_chars = "-_.~?";
    
    // Check if the character is alphanumeric
    if (isalnum(c)) {
        return true;
    }
    
    // Check if the character is a valid special character
    for (int i = 0; i < strlen(valid_chars); i++) {
        if (c == valid_chars[i]) {
            return true;
        }
    }
    
    // Otherwise, the character is not valid
    return false;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);
    
    // Copy the valid characters from the original URL to the sanitized URL
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    
    // Add the null terminator to the sanitized URL
    sanitized_url[j] = '\0';
    
    // Return the sanitized URL
    return sanitized_url;
}

// Function to print the sanitized URL
void print_sanitized_url() {
    printf("Sanitized URL: %s\n", sanitized_url);
}

int main(int argc, char *argv[]) {
    // Get the URL from the command line
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }
    url = argv[1];
    
    // Sanitize the URL
    sanitized_url = sanitize_url(url);
    
    // Print the sanitized URL
    print_sanitized_url();
    
    // Free the memory allocated for the sanitized URL
    free(sanitized_url);
    
    return EXIT_SUCCESS;
}