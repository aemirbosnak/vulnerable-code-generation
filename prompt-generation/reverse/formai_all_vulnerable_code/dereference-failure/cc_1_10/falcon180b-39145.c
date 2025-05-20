//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool is_valid_char(char c) {
    if (isalnum(c) || c == '-') {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char sanitized_url[MAX_URL_LENGTH+1] = "";
    int sanitized_url_length = 0;

    bool in_host = false;
    bool in_path = false;
    bool in_query = false;
    bool in_fragment = false;

    for (int i=0; i<strlen(url); i++) {
        char c = tolower(url[i]);
        if (c == 'http://') {
            in_host = false;
        } else if (c == ':') {
            in_host = true;
        } else if (c == '/') {
            in_path = true;
        } else if (c == '?') {
            in_query = true;
        } else if (c == '#') {
            in_fragment = true;
        } else if (is_valid_char(c)) {
            if (in_host || in_path || in_query || in_fragment) {
                sanitized_url[sanitized_url_length++] = c;
            }
        }
    }

    sanitized_url[sanitized_url_length] = '\0';
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}