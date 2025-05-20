//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LEN 2048

char *sanitize_url(char *url) {
    char *sanitized_url = NULL;
    size_t sanitized_url_len = 0;
    char *ptr = url;
    char *end_ptr = url + strlen(url);

    // Remove leading and trailing whitespace
    while (isspace(*ptr)) {
        ptr++;
    }
    while (isspace(*(end_ptr - 1))) {
        end_ptr--;
    }
    sanitized_url_len = end_ptr - ptr;

    // Remove invalid characters
    while (ptr < end_ptr) {
        if (!isalnum(*ptr) && *ptr!= '.' && *ptr!= '-' && *ptr!= '_' && *ptr!= '~' && *ptr!= '%') {
            if (sanitized_url_len == 0) {
                sanitized_url = malloc(MAX_URL_LEN);
            }
            sanitized_url_len += sprintf(sanitized_url + sanitized_url_len, "%%%02X", *ptr);
        } else {
            if (sanitized_url_len == 0) {
                sanitized_url = malloc(MAX_URL_LEN);
            }
            sanitized_url_len += sprintf(sanitized_url + sanitized_url_len, "%c", *ptr);
        }
        ptr++;
    }

    if (sanitized_url_len == 0) {
        sanitized_url = malloc(MAX_URL_LEN);
        sprintf(sanitized_url, "/");
    } else {
        sanitized_url = malloc(sanitized_url_len + 1);
        strcpy(sanitized_url, "/");
        strcat(sanitized_url, sanitized_url_len > 0? sanitized_url + 1 : "");
    }

    return sanitized_url;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}