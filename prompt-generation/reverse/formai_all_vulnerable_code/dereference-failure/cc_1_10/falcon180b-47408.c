//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is a valid URL character
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == ':' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    i = j = 0;

    // Loop through each character in the URL
    while (url[i]!= '\0') {
        // Check if the character is a valid URL character
        if (is_valid_url_char(url[i])) {
            // If it is, add it to the sanitized URL
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';

    // If the sanitized URL is the same as the original URL, return the original URL
    if (strcmp(sanitized_url, url) == 0) {
        free(sanitized_url);
        return url;
    }

    return sanitized_url;
}

int main() {
    char* url = "https://www.example.com/path/to/page?query=string&other=value";
    char* sanitized_url = sanitize_url(url);

    if (sanitized_url!= url) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }

    return 0;
}