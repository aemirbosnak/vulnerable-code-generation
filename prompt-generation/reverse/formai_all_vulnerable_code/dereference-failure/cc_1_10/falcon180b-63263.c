//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 4096

// Function to sanitize a given URL
void sanitize_url(char *url) {
    int i, j;
    char *scheme = "http://";
    char *host = NULL;
    char *path = NULL;

    // Find the start of the host
    for (i = 0; i < strlen(url); i++) {
        if (url[i] == '/' && i > 7) {
            break;
        }
    }

    // Find the end of the path
    for (j = i; j < strlen(url); j++) {
        if (url[j] == '?' || url[j] == '#') {
            break;
        }
    }

    // Extract the host from the URL
    host = malloc(j - i + 1);
    strncpy(host, &url[i], j - i);
    host[j - i] = '\0';

    // Extract the path from the URL
    path = malloc(j - i + 1);
    strncpy(path, &url[i], j - i);
    path[j - i] = '\0';

    // Sanitize the host
    for (i = 0; i < strlen(host); i++) {
        if (!isalnum(host[i]) && host[i]!= '.' && host[i]!= '-') {
            host[i] = '_';
        }
    }

    // Sanitize the path
    for (i = 0; i < strlen(path); i++) {
        if (!isalnum(path[i]) && path[i]!= '/' && path[i]!= '.' && path[i]!= '-') {
            path[i] = '_';
        }
    }

    // Reassemble the sanitized URL
    sprintf(url, "%s%s%s", scheme, host, path);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get the input URL from the user
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}