//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024
#define MAX_SANITIZED_URL_LENGTH 2048

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_SANITIZED_URL_LENGTH);
    int sanitized_url_length = 0;

    // Remove leading and trailing whitespace
    while (isspace(*url)) {
        url++;
    }
    while (isspace(*(url + strlen(url) - 1))) {
        url[strlen(url) - 1] = '\0';
    }

    // Replace all non-alphanumeric characters with underscores
    for (int i = 0; i < strlen(url); i++) {
        if (!isalnum(url[i])) {
            url[i] = '_';
        }
    }

    // Add underscores between words
    char* word_start = url;
    while (*word_start) {
        if (isalnum(*word_start)) {
            sanitized_url[sanitized_url_length++] = *word_start;
        } else {
            sanitized_url[sanitized_url_length++] = '_';
        }
        word_start++;
    }
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];

    // Prompt the user for a URL
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}