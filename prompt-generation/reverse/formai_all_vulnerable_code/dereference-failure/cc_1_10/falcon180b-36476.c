//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int is_valid_url(char* url);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    int url_length = strlen(url);

    if (url_length > MAX_URL_LENGTH) {
        printf("Error: URL is too long.\n");
        return 1;
    }

    if (!is_valid_url(url)) {
        printf("Error: Invalid URL.\n");
        return 1;
    }

    printf("Valid URL: %s\n", url);
    return 0;
}

int is_valid_url(char* url) {
    char* scheme = strtok(url, "://");
    if (scheme == NULL) {
        return 0;
    }

    if (strcmp(scheme, "http")!= 0 && strcmp(scheme, "https")!= 0) {
        return 0;
    }

    char* host = strtok(NULL, "/");
    if (host == NULL) {
        return 0;
    }

    int host_length = strlen(host);
    int dot_count = 0;
    for (int i = 0; i < host_length; i++) {
        if (host[i] == '.') {
            dot_count++;
        } else if (!isalnum(host[i])) {
            return 0;
        }
    }

    if (dot_count < 1 || dot_count > host_length - 1) {
        return 0;
    }

    return 1;
}