//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 256
#define MAX_PATH_LEN 128

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(sizeof(url));

    if (sanitized_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    char *protocol = strtok(url, ":");
    if (protocol == NULL) {
        printf("Error: Invalid URL format.\n");
        exit(1);
    }

    // Make sure protocol is http or https
    if (strcmp(protocol, "http") != 0 && strcmp(protocol, "https") != 0) {
        printf("Error: Invalid protocol.\n");
        exit(1);
    }

    // Copy protocol to sanitized URL
    strcpy(sanitized_url, protocol);
    strcat(sanitized_url, "://");

    char *path = strtok(NULL, "/");
    if (path == NULL) {
        printf("Error: Invalid URL format.\n");
        exit(1);
    }

    char *hostname = strtok(NULL, "/");
    if (hostname == NULL) {
        printf("Error: Invalid URL format.\n");
        exit(1);
    }

    char *port = strchr(hostname, ':');
    if (port != NULL) {
        char *endptr = NULL;
        long portnum = strtol(port + 1, &endptr, 10);
        if (*endptr != '\0') {
            printf("Error: Invalid port number.\n");
            exit(1);
        }

        if (portnum > 65535) {
            printf("Error: Port number out of range.\n");
            exit(1);
        }

        char *hostname_ = malloc(sizeof(hostname));
        if (hostname_ == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }

        strncpy(hostname_, hostname, port - hostname);
        hostname_[port - hostname] = '\0';

        strcat(sanitized_url, hostname_);
        strcat(sanitized_url, port);

        free(hostname_);
    } else {
        strcat(sanitized_url, hostname);
    }

    strcat(sanitized_url, "/");
    strcat(sanitized_url, path);

    char *query = strchr(path, '?');
    if (query != NULL) {
        int query_len = strlen(query);
        if (query_len > 0) {
            strcat(sanitized_url, "?");

            char *query_ = malloc(sizeof(query));
            if (query_ == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(1);
            }

            strncpy(query_, query + 1, query_len - 1);
            query_[query_len - 1] = '\0';

            strcat(sanitized_url, query_);

            free(query_);
        }
    }

    // Make sure the sanitized URL fits within the buffer
    int sanitized_url_len = strlen(sanitized_url);
    if (sanitized_url_len >= MAX_URL_LEN) {
        printf("Error: Sanitized URL exceeds maximum length.\n");
        exit(1);
    }

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LEN];

    printf("Enter a URL: ");
    scanf("%s", url);

    char *sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}