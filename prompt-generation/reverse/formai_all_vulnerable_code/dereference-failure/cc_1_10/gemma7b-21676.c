//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int sanitized_url_length = 0;

    // Normalize URL case
    url = tolower(url);

    // Remove invalid characters
    for (i = 0; url[i] != '\0'; i++) {
        if (!isalnum(url[i]) && url[i] != '-' && url[i] != '_') {
            url[i] = '_';
        }
    }

    // Remove repeated underscores
    i = 0;
    while (url[i] != '\0') {
        char previous_char = url[i - 1];
        if (url[i] == previous_char && previous_char == '_') {
            url[i] = '_';
        } else {
            sanitized_url[sanitized_url_length++] = url[i];
        }
        i++;
    }

    // Add the terminating null character
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main() {
    char *url = "This is an example URL with invalid characters!?!?";
    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}