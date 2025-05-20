//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sanitize_url(char *url) {
    // Set up a string to store the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);

    // Keep track of the index for the sanitized string
    int index = 0;

    // Loop through the string, character by character
    for (int i = 0; i < strlen(url); i++) {

        // If the character is a space, replace it with %20
        if (url[i] == ' ') {
            sanitized_url[index++] = '%';
            sanitized_url[index++] = '2';
            sanitized_url[index++] = '0';
        }

        // If the character is any other valid character, add it to the sanitized string
        else if (
            (url[i] >= 'a' && url[i] <= 'z') || 
            (url[i] >= 'A' && url[i] <= 'Z') || 
            (url[i] >= '0' && url[i] <= '9') || 
            url[i] == '.' || url[i] == '/' || url[i] == ':' || 
            url[i] == '-' || url[i] == '_' || url[i] == '~'
        ) {
            sanitized_url[index++] = url[i];
        }
    }

    // Null-terminate the sanitized string
    sanitized_url[index] = '\0';

    return sanitized_url;
}

int main() {

    // Sample URL for testing
    char *url = "https://www.example.com/path with spaces/test:123";

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Print the original and sanitized URLs
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory used by the sanitized URL
    free(sanitized_url);

    return 0;
}