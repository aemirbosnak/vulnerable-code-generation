//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 1024

// Function to check if a character is valid for a URL
int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    i = 0;
    while (url[i]!= '\0' && i < MAX_URL_LENGTH - 1) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            j = 0;
            while (isxdigit(url[i])) {
                sanitized_url[i] = url[i];
                i++;
                j++;
                if (j == 2) {
                    break;
                }
            }
            if (j == 0) {
                printf("Error: Invalid URL.\n");
                exit(1);
            }
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char* url = "http://example.com/path/to/file?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}