//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function prototypes
int is_valid_char(char c);
void sanitize_url(const char *url, char *sanitized_url);
void url_encode(const char *url, char *encoded_url);
void display_usage();

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    char sanitized_url[MAX_URL_LENGTH];
    sanitize_url(argv[1], sanitized_url);

    printf("Original URL:  %s\n", argv[1]);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return EXIT_SUCCESS;
}

// Function to display usage information
void display_usage() {
    printf("Usage: url_sanitizer <url>\n");
    printf("Example: url_sanitizer \"http://www.example.com/?param=<value>\"\n");
}

// Function to check if a character is valid in URL
int is_valid_char(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~');
}

// Function to sanitize the URL
void sanitize_url(const char *url, char *sanitized_url) {
    char *encoded_url = (char *)malloc(3 * strlen(url) + 1); // Allocate ample space for encoding
    if (encoded_url == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    // Encode the URL
    url_encode(url, encoded_url);

    // Replace special characters with valid URL characters
    const char *ptr = encoded_url;
    char *s_ptr = sanitized_url;
    
    while (*ptr) {
        if (is_valid_char(*ptr)) {
            *s_ptr++ = *ptr; // Valid character
        } else {
            *s_ptr++ = '%'; // Beginning of encoded character
            sprintf(s_ptr, "%02X", (unsigned char)(*ptr)); // Encode the character
            s_ptr += 2; // Move the pointer past the encoded characters
        }
        ptr++;
    }
    *s_ptr = '\0'; // Null-terminate the sanitized string

    free(encoded_url);
}

// Function to URL encode special characters
void url_encode(const char *url, char *encoded_url) {
    char *ptr = encoded_url;
    
    while (*url) {
        if (is_valid_char(*url)) {
            *ptr++ = *url;
        } else {
            ptr += sprintf(ptr, "%%%02X", (unsigned char)(*url));
        }
        url++;
    }
    *ptr = '\0'; // Null-terminate the encoded URL
}