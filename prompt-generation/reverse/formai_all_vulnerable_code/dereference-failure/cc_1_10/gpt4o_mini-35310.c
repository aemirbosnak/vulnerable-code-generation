//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character
int is_url_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || 
            c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || 
            c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || 
            c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || 
            c == '#' || c == '[' || c == ']' || c == '%');
}

// Function to sanitize the input URL
char* sanitize_url(const char* url) {
    size_t len = strlen(url);
    char* sanitized_url = (char *) malloc(MAX_URL_LENGTH);
    
    if (!sanitized_url) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    for (size_t i = 0; i < len && index < MAX_URL_LENGTH - 1; ++i) {
        if (is_url_char(url[i])) {
            sanitized_url[index++] = url[i];
        } else {
            index += snprintf(sanitized_url + index, MAX_URL_LENGTH - index, "%%%02X", (unsigned char) url[i]);
        }
    }

    sanitized_url[index] = '\0';
    return sanitized_url;
}

// Function to read an URL from standard input
char* read_url_from_input() {
    char* url = (char *) malloc(MAX_URL_LENGTH);
    
    if (!url) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a URL to sanitize: ");
    if (fgets(url, MAX_URL_LENGTH, stdin) != NULL) {
        url[strcspn(url, "\n")] = 0; // Remove newline character if present
        return url;
    } else {
        free(url);
        fprintf(stderr, "Failed to read URL\n");
        exit(EXIT_FAILURE);
    }
}

// Function to free the allocated memory for the URL
void clean_up(char* url) {
    if (url) {
        free(url);
    }
}

int main() {
    char* url_input = read_url_from_input();
    char* sanitized_url = sanitize_url(url_input);

    printf("Original URL: %s\n", url_input);
    printf("Sanitized URL: %s\n", sanitized_url);

    clean_up(url_input);
    clean_up(sanitized_url);
    return 0;
}