//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

int is_valid_url_character(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char *url) {
    int i;
    for (i = 0; i < strlen(url); i++) {
        if (!is_valid_url_character(url[i])) {
            return 0;
        }
    }
    return 1;
}

char *sanitize_url(char *url) {
    int i, j;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    i = 0;
    j = 0;
    while (url[i]) {
        if (is_valid_url_character(url[i])) {
            sanitized_url[j] = url[i];
            i++;
            j++;
        } else {
            i++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitized_url = sanitize_url(url);
    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }
    free(sanitized_url);
    return 0;
}