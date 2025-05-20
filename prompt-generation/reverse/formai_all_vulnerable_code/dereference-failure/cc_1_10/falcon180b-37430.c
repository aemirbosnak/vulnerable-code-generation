//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == '?'|| c == '&' || c == '=' || c == '+' || c == '%') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = (char*) malloc(MAX_LENGTH * sizeof(char));
    while (url[i]) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            sprintf(&sanitized_url[i], "%02X", url[i]);
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char* input_url = "https://example.com/path/to/page?query=string&foo=bar";
    char* sanitized_url = sanitize_url(input_url);
    printf("Input URL: %s\n", input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}