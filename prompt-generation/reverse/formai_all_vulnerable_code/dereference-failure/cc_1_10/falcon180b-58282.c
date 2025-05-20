//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_char(char c);
int is_valid_url(char* url);
char* sanitize_url(char* url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        printf("Valid URL: %s\n", url);
    } else {
        char* sanitized_url = sanitize_url(url);
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }

    return 0;
}

int is_valid_char(char c) {
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '+' || c == '=' || c == '&' || c == '%' || c == '?') {
        return 1;
    }

    return 0;
}

int is_valid_url(char* url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!is_valid_char(url[i])) {
            return 0;
        }
        i++;
    }

    return 1;
}

char* sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (is_valid_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            sprintf(&sanitized_url[i], "%02x", (int) url[i]);
        }
        i++;
    }
    sanitized_url[i] = '\0';

    return sanitized_url;
}