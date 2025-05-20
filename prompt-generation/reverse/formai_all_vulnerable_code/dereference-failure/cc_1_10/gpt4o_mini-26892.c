//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2083  // Maximum URL length
#define SANITIZED_URL_LENGTH 4096  // Maximum sanitized URL length

// Function Prototypes
void sanitize_url(const char *url, char *sanitized_url);
int is_valid_character(char c);
void encode_special_characters(const char *url, char *sanitized_url);

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[SANITIZED_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    
    // Removing the newline character from fgets input
    url[strcspn(url, "\n")] = '\0';

    sanitize_url(url, sanitized_url);
    
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}

void sanitize_url(const char *url, char *sanitized_url) {
    // Check if URL is too long
    if (strlen(url) > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL exceeds maximum length of %d characters.\n", MAX_URL_LENGTH);
        exit(EXIT_FAILURE);
    }
    
    // Initialize sanitized URL
    sanitized_url[0] = '\0';

    // Encode special characters
    encode_special_characters(url, sanitized_url);
}

int is_valid_character(char c) {
    // Allow alphanumeric, ':', '/', '?', '=', '&', and '#' characters in the URL
    return (isalnum(c) || c == ':' || c == '/' || c == '?' || c == '=' || c == '&' || c == '#');
}

void encode_special_characters(const char *url, char *sanitized_url) {
    char temp[3]; // For storing encoded characters (e.g. %20)
    
    for (size_t i = 0; i < strlen(url); ++i) {
        char c = url[i];
        
        if (is_valid_character(c)) {
            strncat(sanitized_url, &c, 1);
        } else {
            // Encode the special character
            snprintf(temp, sizeof(temp), "%%%02X", (unsigned char)c);
            strncat(sanitized_url, temp, strlen(temp));
        }
    }
    
    // Trim and remove any potential trailing whitespace during sanitization
    size_t len = strlen(sanitized_url);
    while (len > 0 && (sanitized_url[len - 1] == ' ' || sanitized_url[len - 1] == '\n')) {
        sanitized_url[--len] = '\0';
    }
}

// Debugging function to display URL sanitization steps
void debug_sanitization(const char *url, const char *sanitized_url) {
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
}