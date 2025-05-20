//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_SANITIZED_URL_LENGTH 4096

int is_valid_url_character(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == ':' || c == '/' || c == '?');
}

char* sanitize_url(char* url) {
    int url_length = strlen(url);
    if (url_length == 0) {
        return url;
    }

    char* sanitized_url = malloc(MAX_SANITIZED_URL_LENGTH);
    char* sanitized_url_ptr = sanitized_url;

    int sanitized_url_length = 0;

    for (int i = 0; i < url_length; i++) {
        char c = url[i];
        if (is_valid_url_character(c)) {
            *sanitized_url_ptr = c;
            sanitized_url_ptr++;
            sanitized_url_length++;
        } else {
            *sanitized_url_ptr = '%';
            sanitized_url_ptr++;
            sprintf(sanitized_url_ptr, "%02X", (unsigned char)c);
            sanitized_url_ptr += 3;
            sanitized_url_length += 3;
        }
    }

    *sanitized_url_ptr = '\0';
    return sanitized_url;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    char* sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}