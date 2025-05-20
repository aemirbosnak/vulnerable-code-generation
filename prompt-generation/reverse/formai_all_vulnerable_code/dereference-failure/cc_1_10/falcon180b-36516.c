//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '.' || c == '-' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    sanitized_url[0] = '\0';
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char *url = "https://www.example.com/path/to/page?query=string#fragment";
    char *sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}