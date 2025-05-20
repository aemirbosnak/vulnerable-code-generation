//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

typedef struct {
    char *url;
    int length;
} URL;

URL *create_url(char *input) {
    URL *url = malloc(sizeof(URL));
    url->url = strdup(input);
    url->length = strlen(url->url);
    return url;
}

void destroy_url(URL *url) {
    free(url->url);
    free(url);
}

int is_valid_scheme(char *scheme) {
    if (strcmp(scheme, "http") == 0 || strcmp(scheme, "https") == 0) {
        return 1;
    }
    return 0;
}

int is_valid_host(char *host) {
    int i;
    for (i = 0; i < strlen(host); i++) {
        if (!isalnum(host[i]) && host[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

int sanitize_url(URL *url) {
    char *scheme = strtok(url->url, "://");
    char *host = strtok(NULL, "/");
    char *path = strtok(NULL, "?");

    if (!is_valid_scheme(scheme)) {
        printf("Invalid scheme\n");
        return 0;
    }

    if (!is_valid_host(host)) {
        printf("Invalid host\n");
        return 0;
    }

    if (strlen(host) > MAX_URL_LENGTH) {
        printf("Host is too long\n");
        return 0;
    }

    char *sanitized_url = malloc(strlen(scheme) + strlen(host) + strlen(path) + 4);
    sprintf(sanitized_url, "%s://%s%s", scheme, host, path);

    destroy_url(url);
    url = create_url(sanitized_url);

    return 1;
}

int main() {
    char input[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(input, MAX_URL_LENGTH, stdin);

    URL *url = create_url(input);
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url->url);

    destroy_url(url);
    return 0;
}