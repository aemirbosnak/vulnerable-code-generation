//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is valid in a URL
int is_valid_char(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '-') ||
        (c == '.') ||
        (c == '_') ||
        (c == '~') ||
        (c == '!') ||
        (c == '$') ||
        (c == '&') ||
        (c == '\'') ||
        (c == '(') ||
        (c == ')') ||
        (c == '*') ||
        (c == '+') ||
        (c == ',') ||
        (c == ';') ||
        (c == '=') ||
        (c == ':') ||
        (c == '@') ||
        (c == '%') ||
        (c == '?')) {
        return 1;
    }
    return 0;
}

// Function to sanitize a URL recursively
void sanitize_url(char* url, int start, int end) {
    if (start >= end) {
        return;
    }
    if (!is_valid_char(url[start])) {
        url[start] = '%';
        start++;
        int hex_start = start;
        while (hex_start < end && isxdigit(url[hex_start])) {
            hex_start++;
        }
        if (hex_start == start || hex_start == end) {
            url[start++] = '%';
        }
        sanitize_url(url, start, end);
    } else {
        sanitize_url(url, start + 1, end);
    }
}

// Function to sanitize a URL
char* sanitize(char* url) {
    int length = strlen(url);
    if (length >= MAX_URL_LENGTH) {
        return NULL;
    }
    sanitize_url(url, 0, length - 1);
    return url;
}

int main() {
    char* url = "https://www.example.com/path/to/page?query=string#fragment";
    char* sanitized_url = sanitize(url);
    if (sanitized_url!= NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
    }
    return 0;
}