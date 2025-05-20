//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to print the usage of the sanitizer
void print_usage() {
    printf("Usage: sanitizer <url>\n");
    printf("Sanitizes and validates a given URL.\n");
}

// Function to check if a character is allowed in a URL
int is_valid_char(char c) {
    return (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' ||
            c == ':' || c == '/' || c == '?' || c == '#' || c == '[' ||
            c == ']' || c == '@' || c == '!' || c == '$' || c == '&' || 
            c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || 
            c == ',' || c == ';' || c == '=');
}

// Function to sanitize a URL
void sanitize_url(const char *input, char *output) {
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (is_valid_char(c)) {
            output[j++] = c;
        } else {
            // percent-encode characters that are not valid
            snprintf(output + j, MAX_URL_LENGTH - j, "%%%02X", (unsigned char)c);
            j += 3; // 3 characters are added in case of percent-encoding
        }
    }
    output[j] = '\0';  // null-terminate the output string
}

// Function to perform validation checks on the URL
int is_valid_url(const char *url) {
    // A simple validation that checks the protocol and host
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        return 0; // Invalid if it does not start with http or https
    }
    return 1; // Valid URL
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *input_url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    // Perform sanitation
    sanitize_url(input_url, sanitized_url);

    // Check if the sanitized URL is valid
    if (is_valid_url(sanitized_url)) {
        printf("Original URL : %s\n", input_url);
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Provided URL is invalid.\n");
    }

    return EXIT_SUCCESS;
}