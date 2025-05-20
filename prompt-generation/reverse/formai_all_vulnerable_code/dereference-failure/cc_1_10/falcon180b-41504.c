//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    int length;
} url_t;

void url_sanitize(url_t *url) {
    if (url == NULL || url->url == NULL) {
        return;
    }

    int i = 0;
    while (i < url->length) {
        if (!isalnum(url->url[i]) && url->url[i]!= '.' && url->url[i]!= '-' && url->url[i]!= '_' && url->url[i]!= '/' && url->url[i]!= '?') {
            url->url[i] = '%';
            i++;
            while (i < url->length && isxdigit(url->url[i])) {
                url->url[i] = '%';
                i++;
            }
        }
        i++;
    }
}

void url_free(url_t *url) {
    free(url->url);
    free(url);
}

url_t *url_parse(char *raw_url) {
    url_t *url = malloc(sizeof(url_t));
    url->url = malloc(MAX_URL_LENGTH);
    strcpy(url->url, raw_url);
    url->length = strlen(raw_url);

    return url;
}

void url_print(url_t *url) {
    printf("Sanitized URL: %s\n", url->url);
}

int main() {
    char raw_url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(raw_url, MAX_URL_LENGTH, stdin);
    raw_url[strcspn(raw_url, "\n")] = '\0';

    url_t *url = url_parse(raw_url);
    url_sanitize(url);
    url_print(url);

    url_free(url);

    return 0;
}