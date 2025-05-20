//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_url_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == ':' || c == '/' || c == '?' || c == '#' || c == '[' || c == ']' || c == '@' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=');
}

// Function to sanitize the URL
void sanitize_url(const char *input, char *output) {
    size_t j = 0;

    for (size_t i = 0; i < strlen(input); i++) {
        if (is_valid_url_char(input[i])) {
            output[j++] = input[i];
        } else {
            // Percent-encode the invalid character
            j += sprintf(output + j, "%%%02X", (unsigned char)input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the string
}

// Helper function to read URL input
void read_url_input(char *url, size_t len) {
    printf("Enter a URL (max length %zu): ", len - 1);
    if (fgets(url, len, stdin) != NULL) {
        // Remove newline character if present
        url[strcspn(url, "\n")] = 0;
    }
}

// Function to display the results
void display_results(const char *original_url, const char *sanitized_url) {
    printf("Original URL: %s\n", original_url);
    printf("Sanitized URL: %s\n", sanitized_url);
}

// The mind-bending aspect
void mind_bending_url_sanitizer() {
    printf("Embark on a journey to the depths of URL sanitization...\n");
    
    char *input_url = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    char *sanitized_url = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    
    if (!input_url || !sanitized_url) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    read_url_input(input_url, MAX_URL_LENGTH);
    sanitize_url(input_url, sanitized_url);
    display_results(input_url, sanitized_url);
    
    printf("What hidden realms of encodings lie beneath...\n");
    
    free(input_url);
    free(sanitized_url);
}

// Main function
int main() {
    mind_bending_url_sanitizer();
    printf("Your journey has ended, but the encoded paths shall remain.\n");
    return 0;
}