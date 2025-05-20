//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= '0' && c <= '9') {
        return 1;
    } else if (c == '-' || c == '_' || c == '.' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

int sanitize_url(char* url) {
    int i = 0;
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));

    while (i < strlen(url)) {
        if (is_valid_url_char(url[i])) {
            sanitized_url[i] = url[i];
        } else {
            sanitized_url[i] = '%';
            i++;
            if (is_valid_url_char(url[i])) {
                sprintf(&sanitized_url[i], "%%%02X", (unsigned char)url[i]);
            } else {
                sprintf(&sanitized_url[i], "%%25");
            }
        }
        i++;
    }

    sanitized_url[i] = '\0';

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}

int main() {
    char* url = "https://example.com/path/to/file?query=string#fragment";
    sanitize_url(url);

    return 0;
}