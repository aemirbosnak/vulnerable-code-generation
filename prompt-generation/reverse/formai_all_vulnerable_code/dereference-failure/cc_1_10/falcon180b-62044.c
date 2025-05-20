//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char* url) {
    int i, j;
    char* safe_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;=%";
    char* unsafe_chars = " \"'<>\\^`{|}";

    // Remove unsafe characters from the URL
    for (i = 0; i < strlen(url); i++) {
        for (j = 0; j < strlen(unsafe_chars); j++) {
            if (url[i] == unsafe_chars[j]) {
                url[i] = '_';
            }
        }
    }

    // Replace multiple slashes with a single slash
    char* p = strrchr(url, '/');
    while (p!= NULL) {
        *p = '/';
        p = strrchr(url, '/');
    }

    // Add a trailing slash if not present
    if (strlen(url) > 1 && url[strlen(url) - 1]!= '/') {
        strcat(url, "/");
    }
}

// Function to print the sanitized URL
void print_sanitized_url(char* url) {
    printf("Sanitized URL: %s\n", url);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    sanitize_url(url);
    print_sanitized_url(url);

    return 0;
}