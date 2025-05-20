//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 1024
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0-9._-/"

bool is_allowed_char(char c) {
    int index;
    for (index = 0; ALLOWED_CHARS[index]; index++) {
        if (ALLOWED_CHARS[index] == c) {
            return true;
        }
    }
    return false;
}

void sanitize_url(char *url) {
    int index, length;
    bool need_escape;

    length = strlen(url);
    for (index = 0; index < length; index++) {
        if (is_allowed_char(url[index])) {
            continue;
        }

        need_escape = false;

        if (index > 0 && is_allowed_char(url[index - 1])) {
            continue;
        }

        if (index < length - 1 && is_allowed_char(url[index + 1])) {
            continue;
        }

        if (url[index] == '%' && is_allowed_char(url[index + 1]) && isxdigit(url[index + 2])) {
            url[index++] = url[index + 1];
            url[index++] = url[index + 1];
            index++;
            need_escape = true;
        }

        if (!need_escape) {
            url[index] = '_';
        }
    }
    url[MAX_URL_LENGTH - 1] = '\0';
}

int main(int argc, char **argv) {
    char url[MAX_URL_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}