//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char *url) {
    int i, j;
    int is_in_query_string = 0;

    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == '?') {
            is_in_query_string = 1;
            continue;
        }

        if (is_in_query_string && (url[i] == '&' || url[i] == '=')) {
            continue;
        }

        if (url[i] == '%' && i < MAX_URL_LENGTH - 3 &&
            isxdigit((int)url[i+1]) && isxdigit((int)url[i+2])) {
            url[i] = (char)strtoul(&url[i], NULL, 16);
            i += 2;
            continue;
        }

        if (!isalnum(url[i]) && url[i] != '/' && url[i] != '.' && url[i] != '-' && url[i] != '_') {
            for (j = i; url[j] != '\0'; j++) {
                url[j] = url[j+1];
            }
            i--;
            continue;
        }
    }

    if (strlen(url) > MAX_URL_LENGTH) {
        printf("URL too long.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sanitize_url(argv[1]);
    printf("Sanitized URL: %s\n", argv[1]);

    return EXIT_SUCCESS;
}