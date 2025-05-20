//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int sanitized_url_length = 0;

    // Remove leading and trailing whitespace
    while (isspace(*url)) {
        url++;
    }
    while (isspace(*(url + strlen(url) - 1))) {
        url[strlen(url) - 1] = '\0';
    }

    // Replace invalid characters with %XX
    char* hex_digits = "0123456789ABCDEF";
    for (int i = 0; i < strlen(url); i++) {
        if (!isalnum(url[i]) && url[i]!= '-') {
            sanitized_url[sanitized_url_length++] = '%';
            sanitized_url[sanitized_url_length++] = hex_digits[url[i] >> 4];
            sanitized_url[sanitized_url_length++] = hex_digits[url[i] & 0x0F];
        } else {
            sanitized_url[sanitized_url_length++] = url[i];
        }
    }
    sanitized_url[sanitized_url_length] = '\0';

    // Return the sanitized URL
    return sanitized_url;
}

int main() {
    char* url = " https://www.example.com/path/file?query=string#fragment ";

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory used by the sanitized URL
    free(sanitized_url);

    return 0;
}