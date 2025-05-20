//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a character is a valid character for a URL
bool is_valid_char(char c) {
    // Alphanumeric characters, hyphen, period, underscore, tilde and slash are valid
    return (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '/');
}

// Function to sanitize a URL by removing any invalid characters
char* sanitize_url(char* url) {
    int len = strlen(url);
    int i = 0, j = 0;

    // Allocate memory for the sanitized URL
    char* sanitized_url = (char*) malloc((len + 1) * sizeof(char));
    if (sanitized_url == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy valid characters from the original URL to the sanitized URL
    while (i < len) {
        if (is_valid_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
        i++;
    }

    // Null terminate the sanitized URL
    sanitized_url[j] = '\0';

    // Free the memory used by the original URL
    free(url);

    return sanitized_url;
}

// Function to print a cheerful message with the sanitized URL
void print_message(char* url) {
    printf("\nHey there, sunshine!\n");
    printf("You entered this cheerful URL: %s\n", url);
    printf("And here's the sanitized version, all shiny and clean:\n");
    printf("%s\n", url);
}

int main(int argc, char* argv[]) {
    // Check if the user provided a URL as an argument
    if (argc != 2) {
        fprintf(stderr, "Please provide a URL as an argument\n");
        exit(EXIT_FAILURE);
    }

    // Sanitize the URL
    char* sanitized_url = sanitize_url(argv[1]);

    // Print a cheerful message with the sanitized URL
    print_message(sanitized_url);

    // Free the memory used by the sanitized URL
    free(sanitized_url);

    return EXIT_SUCCESS;
}