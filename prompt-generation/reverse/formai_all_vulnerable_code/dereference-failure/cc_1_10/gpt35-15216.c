//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

/* Function to sanitize urls */
void sanitize_url(char* url) {
    /* Removing whitespace */
    char buffer[1024];
    int i, j = 0;
    for (i = 0; url[i]; i++) {
        if (!isspace(url[i])) {
            buffer[j++] = url[i];
        }
    }
    buffer[j] = '\0';
    strcpy(url, buffer);

    /* Removing query parameters */
    char* query_start = strchr(url, '?');
    if (query_start != NULL) {
        *query_start = '\0';
    }

    /* Removing trailing slash */
    int url_len = strlen(url);
    if (url_len > 0 && url[url_len - 1] == '/') {
        url[url_len - 1] = '\0';
    }

    /* Converting to lowercase */
    for (i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    /* Adding protocol if necessary */
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        memmove(url + 7, url, url_len + 1);
        memcpy(url, "http://", 7);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}