//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int isValidURL(char *url);
char *sanitizeURL(char *url);

int main() {
    char input[MAX_URL_LENGTH];
    char *sanitizedURL;

    printf("Enter a URL: ");
    fgets(input, MAX_URL_LENGTH, stdin);

    sanitizedURL = sanitizeURL(input);

    if (sanitizedURL!= NULL) {
        printf("Sanitized URL: %s\n", sanitizedURL);
        free(sanitizedURL);
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}

int isValidURL(char *url) {
    int i;
    int valid = 1;

    // Check if URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7)!= 0 && strncmp(url, "https://", 8)!= 0) {
        printf("Invalid URL: URL must start with http:// or https://\n");
        valid = 0;
    }

    // Check for invalid characters
    for (i = 0; i < strlen(url); i++) {
        if (!isalnum(url[i]) && url[i]!= '.' && url[i]!= '-' && url[i]!= '_' && url[i]!= '/') {
            printf("Invalid URL: URL contains invalid characters\n");
            valid = 0;
            break;
        }
    }

    return valid;
}

char *sanitizeURL(char *url) {
    int i;
    int j;
    char *sanitizedURL;

    // Allocate memory for sanitized URL
    sanitizedURL = (char *) malloc(MAX_URL_LENGTH * sizeof(char));

    // Copy valid characters from input URL to sanitized URL
    i = 0;
    j = 0;
    while (isValidURL(url + i)) {
        sanitizedURL[j++] = url[i++];
    }

    // Add "http://" or "https://" prefix if missing
    if (strncmp(sanitizedURL, "http://", 7)!= 0 && strncmp(sanitizedURL, "https://", 8)!= 0) {
        strcpy(sanitizedURL, "http://");
        strcat(sanitizedURL, sanitizedURL);
    }

    // Add "/" suffix if missing
    if (sanitizedURL[strlen(sanitizedURL) - 1]!= '/') {
        strcat(sanitizedURL, "/");
    }

    return sanitizedURL;
}