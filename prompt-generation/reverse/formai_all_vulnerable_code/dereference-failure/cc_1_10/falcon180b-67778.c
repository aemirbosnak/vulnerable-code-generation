//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    int url_length;
} URL;

URL *sanitize_url(char *url) {
    URL *sanitized_url = malloc(sizeof(URL));
    sanitized_url->url = malloc(MAX_URL_LENGTH);
    sanitized_url->url_length = 0;

    char *sanitized_url_ptr = sanitized_url->url;

    for (int i = 0; i < strlen(url); i++) {
        char c = tolower(url[i]);
        if (c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9' ||
            c == '.' || c == '-' || c == '_' || c == '~' ||
            c == '/' || c == '?' || c == '&' || c == '=' ||
            c == '+' || c == '%' || c == '$') {
            *sanitized_url_ptr++ = c;
            sanitized_url->url_length++;
        }
    }

    *sanitized_url_ptr = '\0';
    return sanitized_url;
}

void print_url(URL *url) {
    printf("Sanitized URL: %s\n", url->url);
}

int main() {
    char input_url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);

    URL *sanitized_url = sanitize_url(input_url);

    print_url(sanitized_url);

    free(sanitized_url->url);
    free(sanitized_url);

    return 0;
}