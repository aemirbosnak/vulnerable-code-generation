//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else if (c == '%') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url_scheme(const char* scheme) {
    if (strcmp(scheme, "http") == 0 || strcmp(scheme, "https") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url_host(const char* host) {
    int len = strlen(host);
    if (len >= 1 && len <= 255) {
        for (int i = 0; i < len; i++) {
            if (!is_valid_url_char(host[i])) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(const char* url) {
    int len = strlen(url);
    if (len >= 7 && len <= MAX_URL_LEN) {
        const char* scheme = strstr(url, "://");
        if (scheme!= NULL && is_valid_url_scheme(scheme)) {
            scheme += 3;
            const char* host = strstr(scheme, "/");
            if (host!= NULL && is_valid_url_host(host)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    const char* url = argv[1];
    if (is_valid_url(url)) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}