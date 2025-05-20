//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to sanitize URL
char* sanitizeURL(char* url) {
    // Define the allowable characters in a URL
    char allowed[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=";

    int len = strlen(url);

    // Allocate memory for the sanitized URL
    char* new_url = (char*)malloc(sizeof(char) * (len + 1));
    int new_len = 0;

    // Loop through each character in the original URL
    for (int i = 0; i < len; i++) {
        char c = url[i];
        // Check if the character is allowed
        if (strchr(allowed, c) != NULL) {
            // If allowed, add it to the new URL
            new_url[new_len++] = c;
        } else if (isspace(c)) {
            // Replace spaces with %20
            new_url[new_len++] = '%';
            new_url[new_len++] = '2';
            new_url[new_len++] = '0';
        } else {
            // Replace other characters with a hyphen
            new_url[new_len++] = '-';
        }
    }

    // Null-terminate the new URL
    new_url[new_len] = '\0';

    return new_url;
}

int main() {
    char url[1000];
    printf("Enter a URL to sanitize:\n");
    fgets(url, 1000, stdin);

    // Remove the newline character from the end of the input string
    url[strcspn(url, "\n")] = '\0';

    char* sanitized_url = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    return 0;
}