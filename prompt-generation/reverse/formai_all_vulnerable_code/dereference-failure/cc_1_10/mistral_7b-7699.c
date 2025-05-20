//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char *url) {
    char *scheme_start = strchr(url, "://");
    char *scheme_end = scheme_start;
    if (scheme_start != NULL) {
        scheme_end = strchr(scheme_start, '/');
        if (scheme_end != NULL) {
            *scheme_end = '\0';
        }
    }

    char *path_start = scheme_end;
    if (scheme_start == NULL) {
        path_start = url;
    }

    char *query_start = strchr(path_start, '?');
    if (query_start != NULL) {
        *query_start = '\0';
        path_start = query_start + 1;
    }

    char *fragment_start = strchr(path_start, '#');
    if (fragment_start != NULL) {
        *fragment_start = '\0';
        path_start = fragment_start;
    }

    int length = strlen(path_start);
    for (int i = 0; i < length; i++) {
        if (path_start[i] == '+') {
            path_start[i] = ' ';
        } else if (path_start[i] == '%') {
            if (length - i < 3) {
                fprintf(stderr, "Invalid URL encoding\n");
                exit(EXIT_FAILURE);
            }
            int hex = strtol(&path_start[i + 1], NULL, 16);
            if (hex < 0x20 || hex > 0x7E) {
                fprintf(stderr, "Invalid URL character %#x\n", hex);
                exit(EXIT_FAILURE);
            }
            path_start[i] = (char)hex;
            i += 2;
        }
    }

    printf("%s\n", path_start);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s URL\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sanitize_url(argv[1]);

    return EXIT_SUCCESS;
}