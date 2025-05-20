//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_SIZE 2048
#define ALLOWED_SCHEMES "http://https://ftp://ftps://"
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;=%"

int is_valid_scheme(char *scheme);
int is_valid_char(char c);
int is_valid_url(char *url);

int main() {
    char url[MAX_URL_SIZE];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_SIZE, stdin);
    url[strcspn(url, "\n")] = '\0';

    if (is_valid_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}

int is_valid_scheme(char *scheme) {
    char *allowed_schemes = ALLOWED_SCHEMES;
    while (*scheme && *allowed_schemes) {
        if (*scheme!= *allowed_schemes) {
            return 0;
        }
        scheme++;
        allowed_schemes++;
    }
    return *scheme == '\0';
}

int is_valid_char(char c) {
    char *allowed_chars = ALLOWED_CHARS;
    while (*allowed_chars) {
        if (c == *allowed_chars) {
            return 1;
        }
        allowed_chars++;
    }
    return 0;
}

int is_valid_url(char *url) {
    char *scheme_end = strstr(url, "://");
    if (!scheme_end) {
        return 0;
    }

    char *host_start = scheme_end + 3;
    char *host_end = strchr(host_start, '/');
    if (!host_end) {
        host_end = strchr(host_start, '?');
    }

    if (!is_valid_scheme(url)) {
        return 0;
    }

    for (char *p = host_start; p < host_end; p++) {
        if (!is_valid_char(*p)) {
            return 0;
        }
    }

    return 1;
}