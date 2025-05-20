//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1024
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0-9.-_"

bool is_allowed_char(char c) {
    return (strchr(ALLOWED_CHARS, c) != NULL);
}

void sanitize_url(char *url) {
    int i = 0, j = 0;
    bool in_query_string = false;

    while (url[i] != '\0') {
        if (url[i] == '&') {
            in_query_string = true;
            i++;
            continue;
        }

        if (!in_query_string && !is_allowed_char(url[i])) {
            url[i] = '_';
        }

        if (is_allowed_char(url[i])) {
            url[j++] = url[i];
        }

        i++;
    }

    url[j] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char input_url[MAX_URL_LENGTH];
    strcpy(input_url, argv[1]);

    sanitize_url(input_url);

    printf("Sanitized URL: %s\n", input_url);

    return 0;
}