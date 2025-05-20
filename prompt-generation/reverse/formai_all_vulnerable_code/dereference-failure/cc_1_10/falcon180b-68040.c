//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *url_get_host(char *url) {
    char *host = strdup(url);
    char *at_pos = strchr(host, '@');
    if (at_pos) {
        *at_pos = '\0';
    }
    char *colon_pos = strrchr(host, ':');
    if (colon_pos) {
        *colon_pos = '\0';
    }
    return host;
}

char *url_get_path(char *url) {
    char *path = strdup(url);
    char *slash_pos = strrchr(path, '/');
    if (slash_pos) {
        *slash_pos = '\0';
    }
    return path;
}

int main() {
    char *line = NULL;
    size_t len = 0;

    while ((getline(&line, &len, stdin))!= -1) {
        if (len > MAX_LINE_LENGTH) {
            printf("Line too long: %s\n", line);
            free(line);
            continue;
        }

        char *url = strstr(line, "http://");
        if (!url) {
            url = strstr(line, "https://");
            if (!url) {
                free(line);
                continue;
            }
        }

        char *host = url_get_host(url);
        char *path = url_get_path(url);

        printf("Host: %s\n", host);
        printf("Path: %s\n", path);

        free(line);
    }

    return 0;
}