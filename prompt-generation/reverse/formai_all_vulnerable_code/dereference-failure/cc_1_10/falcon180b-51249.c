//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '/' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',') {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int length = strlen(url);
    if (length > MAX_URL_LENGTH) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url) {
    int length = strlen(url);
    if (length > MAX_URL_LENGTH) {
        url[MAX_URL_LENGTH - 1] = '\0';
        printf("URL sanitized due to length limit.\n");
    }
    for (int i = 0; i < length; i++) {
        if (!is_valid_url_character(url[i])) {
            url[i] = '-';
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    if (!is_valid_url(url)) {
        sanitize_url(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Valid URL: %s\n", url);
    }
    return 0;
}