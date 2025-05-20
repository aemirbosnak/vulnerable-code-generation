//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1024

bool is_valid_url_char(char c) {
    if (isalnum(c) || c == '-') {
        return true;
    } else if (c == '.') {
        return true;
    } else if (c == '_') {
        return true;
    } else if (c == '~') {
        return true;
    } else {
        return false;
    }
}

bool is_valid_url(char* url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return false;
        }
    }
    return true;
}

char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char* url = "https://example.com/path/to/resource?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}