//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_safe_character(char ch) {
    // Allow alphanumeric characters, '.', '-', '_', '~'
    return (isalnum(ch) || ch == '.' || ch == '-' || ch == '_' || ch == '~');
}

void sanitize_url(const char *url, char *sanitized_url) {
    char *ptr = sanitized_url;
    
    while (*url) {
        if (is_safe_character(*url)) {
            *ptr++ = *url; // Copy safe character
        } else {
            // Encode unsafe character as %XX
            ptr += sprintf(ptr, "%%%02X", (unsigned char)*url);
        }
        url++;
    }
    *ptr = '\0'; // Null-terminate the sanitized URL
}

void read_config(const char *filename, int *max_length) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open configuration file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    fscanf(file, "MAX_URL_LENGTH=%d", max_length);
    fclose(file);
}

int main(int argc, char *argv[]) {
    char sanitized_url[MAX_URL_LENGTH];
    char *input_url = NULL;
    int max_length = MAX_URL_LENGTH;

    // Read configuration file if provided
    if (argc > 1) {
        read_config(argv[1], &max_length);
    }

    printf("Enter a URL to sanitize (max length %d): ", max_length);
    input_url = (char*)malloc(max_length);
    if (!input_url) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Get the raw URL input from the user
    fgets(input_url, max_length, stdin);
    // Remove newline character at the end, if present
    input_url[strcspn(input_url, "\n")] = '\0';
    
    // Sanitize the URL
    sanitize_url(input_url, sanitized_url);
    
    // Display the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    
    // Free allocated memory
    free(input_url);
    
    return EXIT_SUCCESS;
}