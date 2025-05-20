//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;="

// Function to check if a character is a valid URL character
int is_valid_char(char c) {
    return strchr(ALLOWED_CHARS, c) != NULL;
}

// Function to sanitize the URL
void sanitize_url(const char *input, char *output) {
    while (*input) {
        // Check if the current character is valid
        if (is_valid_char(*input)) {
            *output++ = *input; // Copy valid character to output
        }
        else {
            // If the character isn't valid, we encode it as a percent-encoded character
            sprintf(output, "%%%02X", (unsigned char)*input);
            output += 3; // Move past the encoded character
        }
        input++; // Move to the next character in input
    }
    *output = '\0'; // Null-terminate the output string
}

// Function to trim spaces from the URL
void trim_spaces(const char *input, char *output) {
    while (isspace((unsigned char)*input)) input++; // Skip leading spaces
    char *end = (char *)input + strlen(input) - 1; // Point to the end of the string
    while (end > input && isspace((unsigned char)*end)) end--; // Skip trailing spaces
    // Copy the trimmed string to output
    strncpy(output, input, end - input + 1);
    output[end - input + 1] = '\0'; // Null-terminate the output string
}

// Main function to execute the URL sanitization process
int main() {
    char input_url[MAX_URL_LENGTH];
    char trimmed_url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];

    printf("Welcome to the URL Sanitizer! 🚀\n");
    printf("Please enter a URL to sanitize (max length %d): ", MAX_URL_LENGTH - 1);
    if (!fgets(input_url, sizeof(input_url), stdin)) {
        perror("Error reading input URL");
        return 1;
    }

    // Remove the newline character from fgets
    input_url[strcspn(input_url, "\n")] = 0;

    // Trim spaces from the input URL
    trim_spaces(input_url, trimmed_url);
    printf("Trimmed URL: %s\n", trimmed_url);

    // Sanitize the trimmed URL
    sanitize_url(trimmed_url, sanitized_url);
    printf("Sanitized URL: %s\n", sanitized_url);

    printf("Thank you for using the URL Sanitizer! 🍀\n");
    return 0;
}