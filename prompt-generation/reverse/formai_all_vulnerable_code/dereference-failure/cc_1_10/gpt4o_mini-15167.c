//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check whether a character is allowed in a URL
int is_safe_char(char ch) {
    return (isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~' || 
            ch == '/' || ch == ':' || ch == '?' || ch == '&' || ch == '=' || 
            ch == '+' || ch == '#' || ch == '%');
}

// Function to sanitize the URL
char* sanitize_url(const char* input_url) {
    if (input_url == NULL || strlen(input_url) > MAX_URL_LENGTH) {
        return NULL;
    }

    char* sanitized_url = (char*)malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    size_t sanitized_index = 0;
    for (size_t i = 0; i < strlen(input_url); i++) {
        char current_char = input_url[i];
        if (is_safe_char(current_char)) {
            sanitized_url[sanitized_index++] = current_char;
        } else {
            // Replace unsafe character with a placeholder (e.g., '%xx' encoding)
            snprintf(sanitized_url + sanitized_index, MAX_URL_LENGTH - sanitized_index, "%%%02X", (unsigned char)current_char);
            sanitized_index += 3; // Because %xx encoding takes 3 characters
        }
    }
    sanitized_url[sanitized_index] = '\0'; // Null-terminate the sanitized string

    return sanitized_url;
}

// Function to trim whitespace from the start and end of a string
char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // Null-terminate trimmed string

    return str;
}

// Main function
int main() {
    char input_url[MAX_URL_LENGTH];

    printf("Enter the URL to sanitize: ");
    if (fgets(input_url, sizeof(input_url), stdin) == NULL) {
        fprintf(stderr, "Input error\n");
        return EXIT_FAILURE;
    }

    // Remove the newline character at the end if it exists
    size_t length = strlen(input_url);
    if (length > 0 && input_url[length - 1] == '\n') {
        input_url[length - 1] = '\0';
    }

    trim_whitespace(input_url); // Trim any leading/trailing whitespace

    char* result = sanitize_url(input_url);
    if (result == NULL) {
        fprintf(stderr, "URL sanitization error\n");
        return EXIT_FAILURE;
    }

    printf("Sanitized URL: %s\n", result);
    free(result); // Free allocated memory

    return EXIT_SUCCESS;
}