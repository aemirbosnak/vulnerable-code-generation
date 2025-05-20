//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(const char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int sanitized_url_length = 0;
    int i = 0;
    int j = 0;

    // Remove leading and trailing spaces
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[j])) {
        j--;
    }

    if (i > j) {
        strcpy(sanitized_url, "");
        return sanitized_url;
    }

    // Copy the URL up to the query string
    while (url[i]!= '?') {
        if (sanitized_url_length >= MAX_URL_LENGTH - 1) {
            break;
        }
        sanitized_url[sanitized_url_length] = url[i];
        sanitized_url_length++;
        i++;
    }

    // Add a placeholder for the query string
    sanitized_url[sanitized_url_length] = '?';
    sanitized_url_length++;

    // Copy the query string, removing any illegal characters
    while (url[i]!= '\0') {
        if (sanitized_url_length >= MAX_URL_LENGTH - 1) {
            break;
        }
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '~') {
            sanitized_url[sanitized_url_length] = url[i];
            sanitized_url_length++;
        }
        i++;
    }

    // Add a null terminator
    sanitized_url[sanitized_url_length] = '\0';

    return sanitized_url;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);

    if (sanitized_url == NULL) {
        fprintf(stderr, "Invalid URL\n");
        return 1;
    }

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}