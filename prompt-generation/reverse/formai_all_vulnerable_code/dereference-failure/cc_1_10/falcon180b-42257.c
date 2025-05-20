//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    switch (c) {
        case '.':
        case '_':
        case '~':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int is_valid_url(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i = 0;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            sanitized_url[i] = '2';
            i++;
            sanitized_url[i] = '0';
            i++;
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}