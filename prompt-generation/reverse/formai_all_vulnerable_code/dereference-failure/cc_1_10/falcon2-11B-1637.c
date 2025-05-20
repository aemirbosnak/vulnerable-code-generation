//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024
#define MAX_HOST_LENGTH 256
#define MAX_PATH_LENGTH 1024

typedef struct {
    char* host;
    char* path;
} URL;

void sanitize_url(char* url) {
    URL* u = malloc(sizeof(URL));
    if (url == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    u->host = strdup(url);
    if (u->host == NULL) {
        printf("Memory allocation error!\n");
        free(u->host);
        free(u);
        return;
    }
    char* host = strtok(u->host, "://");
    if (host == NULL) {
        printf("Invalid URL format!\n");
        free(u->host);
        free(u);
        return;
    }
    char* path = strtok(NULL, "/");
    if (path == NULL) {
        printf("Invalid URL format!\n");
        free(u->host);
        free(u);
        return;
    }
    u->path = strdup(path);
    if (u->path == NULL) {
        printf("Memory allocation error!\n");
        free(u->host);
        free(u);
        return;
    }
    printf("Sanitized URL: %s\n", u->host);
    printf("Path: %s\n", u->path);
    free(u->host);
    free(u->path);
    free(u);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove trailing newline
    sanitize_url(url);
    return 0;
}