//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int i = 0, j = 0;

    if (url == NULL || strlen(url) == 0) {
        return NULL;
    }

    // Remove leading/trailing whitespace
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[strlen(url) - 1])) {
        url[strlen(url) - 1] = '\0';
    }

    // Copy sanitized characters to new string
    while (url[i]!= '\0') {
        if (isalnum(url[i]) || url[i] == '-') {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);
    char* sanitized_url = sanitize_url(input_url);

    if (sanitized_url == NULL) {
        printf("Invalid URL\n");
    } else {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }

    return 0;
}