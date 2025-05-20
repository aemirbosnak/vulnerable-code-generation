//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/?#[]@!$&'()*+,;=%"
#define ALLOWED_HOSTS "www.google.com"

int is_allowed_character(char c) {
    if (strchr(ALLOWED_CHARACTERS, c)!= NULL) {
        return 1;
    }
    return 0;
}

int is_allowed_host(char *host) {
    if (strstr(ALLOWED_HOSTS, host)!= NULL) {
        return 1;
    }
    return 0;
}

char *sanitize_url(char *unsanitized_url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    char *current_position = sanitized_url;
    int is_valid_protocol = 0;

    if (unsanitized_url == NULL) {
        strcpy(sanitized_url, "");
        return sanitized_url;
    }

    if (strncmp(unsanitized_url, "http://", 7) == 0 ||
        strncmp(unsanitized_url, "https://", 8) == 0) {
        is_valid_protocol = 1;
    }

    if (!is_valid_protocol) {
        strcpy(sanitized_url, "");
        return sanitized_url;
    }

    while (*unsanitized_url!= '\0') {
        if (is_allowed_character(*unsanitized_url)) {
            *current_position = *unsanitized_url;
            current_position++;
        }
        unsanitized_url++;
    }
    *current_position = '\0';

    if (is_allowed_host(sanitized_url)) {
        return sanitized_url;
    } else {
        free(sanitized_url);
        return "";
    }
}

int main() {
    char unsanitized_url[] = "hxxp://www.google.com/search?q=test";
    char *sanitized_url = sanitize_url(unsanitized_url);

    if (sanitized_url!= NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL.\n");
    }

    return 0;
}