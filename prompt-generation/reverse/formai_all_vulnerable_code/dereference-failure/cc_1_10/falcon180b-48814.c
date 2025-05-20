//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '-' || c == '.' || c == '_' || c == '~' || c == '!' ||
        c == '$' || c == '&' || c == "'" || c == '(' || c == ')' ||
        c == '*' || c == '+' || c == ',' || c == ';' || c == '=' ||
        c == ':' || c == '@' || c == '\\') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url) && i < MAX_URL_LENGTH; i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url;
    sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    for (i = 0, j = 0; i < strlen(url) && j < MAX_URL_LENGTH; i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char input_url[MAX_URL_LENGTH];
    char *sanitized_url;
    printf("Enter a URL: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);
    sanitized_url = sanitize_url(input_url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}