//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
    if (isalnum(c) || strchr(".-_~:/?#[]@!$&'()*+,;=%", c)!= NULL) {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];
    char *sanitized_url = sanitize_url(url);

    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }

    free(sanitized_url);
    return 0;
}