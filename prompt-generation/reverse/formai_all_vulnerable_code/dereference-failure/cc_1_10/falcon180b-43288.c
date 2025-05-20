//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL by removing invalid characters
char* sanitize_url(char* url) {
    int i = 0, j = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));

    // Copy valid characters to sanitized URL
    while (url[i]) {
        if (isalnum(url[i]) || url[i] == '-') {
            sanitized_url[j++] = url[i];
        } else if (url[i] == '.') {
            if (j > 0 && sanitized_url[j-1]!= '.') {
                sanitized_url[j++] = url[i];
            }
        }
        i++;
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

// Function to check if a URL is valid
int is_valid_url(char* url) {
    char* sanitized_url = sanitize_url(url);

    // Check if sanitized URL is empty
    if (strlen(sanitized_url) == 0) {
        return 0;
    }

    // Check if sanitized URL contains only valid characters
    int i = 0;
    while (sanitized_url[i]) {
        if (!isalnum(sanitized_url[i]) && sanitized_url[i]!= '-') {
            return 0;
        }
        i++;
    }

    return 1;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}