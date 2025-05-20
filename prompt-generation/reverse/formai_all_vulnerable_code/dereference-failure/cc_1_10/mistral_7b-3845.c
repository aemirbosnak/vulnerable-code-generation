//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>

#define MAX_LENGTH 256

bool is_alnum(char c) {
    return isalnum(c);
}

bool is_hex(char c) {
    return (isdigit(c) || (isalpha(c) && isupper(c) && (c >= 'A' && c <= 'F')));
}

void sanitize_url(char *url) {
    int length = strlen(url), i = 0;
    char output[MAX_LENGTH];

    if (length > MAX_LENGTH) {
        fprintf(stderr, "URL too long\n");
        exit(1);
    }

    for (; i < length; ++i) {
        char c = url[i];

        if (is_alnum(c) || c == '.' || c == '_' || (c >= '0' && c <= '9') || (c == '~' && i == 0)) {
            output[i] = c;
            continue;
        }

        if (c == '+' && (i > 0 && is_alnum(url[i - 1]))) {
            output[i] = ' ';
            continue;
        }

        if (c == '%' && i < length - 2 && is_hex(url[i + 1]) && is_hex(url[i + 2])) {
            output[i++] = url[i + 1];
            output[i++] = url[i + 2];
            i += 2;
            continue;
        }

        if (c == '%' && i == length - 1) {
            fprintf(stderr, "Invalid URL: missing characters after '%'\n");
            exit(1);
        }

        if (c == '%') {
            fprintf(stderr, "Invalid URL: '%' should be followed by two hexadecimal digits\n");
            exit(1);
        }

        fprintf(stderr, "Invalid character '%c' in URL\n", c);
        exit(1);
    }

    output[i] = '\0';
    strcpy(url, output);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    sanitize_url(argv[1]);

    printf("Sanitized URL: %s\n", argv[1]);

    return 0;
}