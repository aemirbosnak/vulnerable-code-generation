//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define INVALID_CHAR_MSG "Contains invalid characters."

// Function prototypes
void sanitize_url(const char *input_url, char *sanitized_url);
int is_valid_char(char c);
void print_help();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_help();
        return EXIT_FAILURE;
    }

    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(argv[1], sanitized_url);
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return EXIT_SUCCESS;
}

void sanitize_url(const char *input_url, char *sanitized_url) {
    if (strlen(input_url) > MAX_URL_LENGTH - 1) {
        fprintf(stderr, "Error: URL exceeds maximum allowed length of %d characters.\n", MAX_URL_LENGTH - 1);
        exit(EXIT_FAILURE);
    }

    char *ptr = sanitized_url;
    
    while (*input_url) {
        if (is_valid_char(*input_url)) {
            *ptr++ = *input_url;
        } else {
            fprintf(stderr, "Error: URL %s: %s\n", input_url, INVALID_CHAR_MSG);
            exit(EXIT_FAILURE);
        }
        input_url++;
    }
    
    *ptr = '\0'; // Null-terminate the sanitized string
}

int is_valid_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' ||
            c == ':' || c == '/' || c == '?' || c == '#' || c == '[' ||
            c == ']' || c == '@' || c == '!' || c == '$' || c == '&' ||
            c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' ||
            c == ',' || c == ';' || c == '=');
}

void print_help() {
    fprintf(stderr, "Usage: urlsanitizer <URL>\n");
    fprintf(stderr, "Sanitizes a given URL by removing invalid characters.\n");
}