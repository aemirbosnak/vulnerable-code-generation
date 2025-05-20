//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>

#define MAX_LEN 256

// Function to check if a character is valid in a URL
bool is_valid_char(char c) {
    return (isalnum(c) || (c == '~' || c == '.' || c == '-' || c == '_' || c == '~' || c == ':' || c == '/'));
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    int len = strlen(url);
    int i, j;

    char* sanitized_url = malloc(len + 1);
    strncpy(sanitized_url, url, len + 1);

    // Remove leading and trailing whitespaces
    for(i = 0; sanitized_url[i] != '\0'; i++) {
        if(isspace(sanitized_url[i])) {
            for(j = i; sanitized_url[j] != '\0'; j++) {
                sanitized_url[j] = sanitized_url[j+1];
            }
            len--;
            i--;
        }
    }

    // Sanitize the URL
    for(i = 0, j = 0; sanitized_url[i] != '\0'; i++) {
        if(is_valid_char(sanitized_url[i])) {
            sanitized_url[j++] = sanitized_url[i];
        }
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_LEN];
    char* sanitized_url;

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_LEN, stdin);

    // Remove newline character from the input
    url[strcspn(url, "\n")] = '\0';

    sanitized_url = sanitize_url(url);

    if(sanitized_url == NULL) {
        perror("Error in sanitizing URL");
        exit(EXIT_FAILURE);
    }

    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    return EXIT_SUCCESS;
}