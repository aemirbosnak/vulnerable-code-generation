//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else if (c == '.') {
        return 1;
    } else if (c == '_') {
        return 1;
    } else if (c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    i = 0;
    for (j = 0; j < strlen(url); j++) {
        if (is_valid_url_char(url[j])) {
            sanitized_url[i++] = url[j];
        }
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char *url = "hTtPs://www.example.com/index.html?param1=value1&param2=value2#fragment";
    char *sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}