//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sanitize_url(char *url);

int main() {
    char url[1000];

    printf("Enter the URL:");
    fgets(url, 1000, stdin);

    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}

char *sanitize_url(char *url) {
    char *sanitized_url = (char*)malloc(sizeof(char) * strlen(url));
    int j = 0;

    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        if (c == '%') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '5';
        }
        else if (c == '&') {
            sanitized_url[j++] = '&';
            sanitized_url[j++] = 'a';
            sanitized_url[j++] = 'm';
            sanitized_url[j++] = 'p';
            sanitized_url[j++] = ';';
        }
        else if (c == '<') {
            sanitized_url[j++] = '&';
            sanitized_url[j++] = 'l';
            sanitized_url[j++] = 't';
            sanitized_url[j++] = ';';
        }
        else {
            sanitized_url[j++] = c;
        }
    }

    sanitized_url[j] = '\0';
    return sanitized_url;
}