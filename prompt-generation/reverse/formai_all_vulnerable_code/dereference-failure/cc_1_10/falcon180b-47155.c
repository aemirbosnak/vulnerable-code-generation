//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

// Function to sanitize a URL
void sanitize_url(char *url) {
    int i = 0, j = 0;
    char sanitized_url[MAX_URL_LENGTH];

    // Remove leading and trailing whitespace
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[j])) {
        j--;
    }

    // Copy the sanitized URL
    strncpy(sanitized_url, url + i, j - i + 1);
    sanitized_url[j - i + 1] = '\0';

    // Convert all characters to lowercase
    for (i = 0; i < strlen(sanitized_url); i++) {
        sanitized_url[i] = tolower(sanitized_url[i]);
    }

    // Remove consecutive dots
    char *ptr = sanitized_url;
    while (*ptr) {
        if (*ptr == '.') {
            if (ptr > sanitized_url && ptr[-1] == '.') {
                *ptr = '\0';
                strcat(sanitized_url, ptr + 1);
            }
        }
        ptr++;
    }

    // Remove trailing dot
    if (sanitized_url[strlen(sanitized_url) - 1] == '.') {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }

    // Copy the sanitized URL back to the original buffer
    strcpy(url, sanitized_url);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}