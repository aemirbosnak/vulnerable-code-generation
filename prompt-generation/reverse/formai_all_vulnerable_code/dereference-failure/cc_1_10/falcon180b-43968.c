//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' ||
        c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' ||
        c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '?' ||
        c == '@' || c == '[' || c == '\\' || c == ']' || c == '^' || c == '`' ||
        c == '{' || c == '|' || c == '}' || c == '~') {
        return 1;
    }
    return 0;
}

int is_valid_url(char* url) {
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

char* sanitize_url(char* url) {
    int length = strlen(url);
    char* sanitized_url = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            sprintf(&sanitized_url[i], "%02X", (unsigned char)url[i]);
        }
    }
    sanitized_url[length] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH] = "https://example.com/path/to/page?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}