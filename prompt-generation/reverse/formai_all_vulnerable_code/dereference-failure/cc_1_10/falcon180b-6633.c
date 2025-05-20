//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == ';' || c == '$' || c == ',') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char* url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

int sanitize_url(char* url) {
    int i, j;
    char sanitized_url[MAX_URL_LENGTH];
    j = 0;
    for (i = 0; i < strlen(url); i++) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
    return 1;
}

int main(int argc, char** argv) {
    int i;
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    for (i = 1; i < argc; i++) {
        char* url = argv[i];
        if (!is_valid_url(url)) {
            sanitize_url(url);
            printf("Sanitized URL: %s\n", url);
        } else {
            printf("URL is already valid: %s\n", url);
        }
    }
    return 0;
}