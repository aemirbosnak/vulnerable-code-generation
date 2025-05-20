//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HURL_MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    int length;
} hurl_url_t;

int hurl_url_encode(hurl_url_t *url) {
    int i, j;
    char *new_url = malloc(HURL_MAX_URL_LENGTH);
    if (new_url == NULL) {
        return -1;
    }
    for (i = 0, j = 0; i < url->length; i++) {
        switch (url->url[i]) {
            case ' ':
                new_url[j++] = '+';
                break;
            case '&':
                new_url[j++] = '%';
                new_url[j++] = '2';
                new_url[j++] = '6';
                break;
            case '=':
                new_url[j++] = '%';
                new_url[j++] = '3';
                new_url[j++] = 'D';
                break;
            default:
                new_url[j++] = url->url[i];
                break;
        }
    }
    new_url[j] = '\0';
    free(url->url);
    url->url = new_url;
    url->length = j;
    return 0;
}

int main(int argc, char **argv) {
    hurl_url_t url;
    int i;

    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    url.url = argv[1];
    url.length = strlen(argv[1]);

    if (hurl_url_encode(&url) != 0) {
        printf("Error: Could not encode URL.\n");
        return 1;
    }

    printf("Encoded URL: %s\n", url.url);

    free(url.url);

    return 0;
}