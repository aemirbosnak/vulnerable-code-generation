//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 4096

int is_valid_url_char(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '%' || c == '?' || c == '/' || c == '\\' || c == '|' || c == '<' || c == '>' || c == '`' || c == '{')
        return 1;
    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_url_char(url[i]))
            return 0;
        i++;
    }
    return 1;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            char hex_value[3];
            sprintf(hex_value, "%02X", url[i]);
            strcat(sanitized_url, hex_value);
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

int main() {
    char* url = "https://example.com/path/to/page?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}