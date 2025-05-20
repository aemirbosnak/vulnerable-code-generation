//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid for a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '!') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = (char*)malloc(MAX_URL_LENGTH * sizeof(char));
    sanitized_url[0] = '\0';

    // Copy the original URL to the sanitized URL
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

// Function to print a sanitized URL
void print_sanitized_url(char* url) {
    printf("Sanitized URL: %s\n", url);
}

// Main function
int main() {
    char* url;

    // Get a URL from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    print_sanitized_url(sanitized_url);

    // Free the memory used by the sanitized URL
    free(sanitized_url);

    return 0;
}