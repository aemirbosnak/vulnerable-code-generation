//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This program is a C URL sanitizer that takes in a raw URL as input, and returns a sanitized URL as output

char *sanitize_url(char *url) {
    int length = strlen(url);
    char *sanitized_url = (char *) malloc(length + 1);
    int i, j = 0;
    int has_slash = 0;
    int has_dot = 0;

    //Loop through the URL and sanitize it
    for (i = 0; i < length; i++) {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')) {
            sanitized_url[j++] = url[i];
            has_dot = 0;
        }
        else if (url[i] == '/') {
            if (!has_slash) {
                sanitized_url[j++] = url[i];
                has_slash = 1;
                has_dot = 0;
            }
        }
        else if (url[i] == '.') {
            if (!has_dot && !has_slash) {
                sanitized_url[j++] = url[i];
                has_dot = 1;
            }
        }
    }

    if (sanitized_url[j - 1] == '/') {
        sanitized_url[j - 1] = '\0';
    }
    else {
        sanitized_url[j] = '\0';
    }

    return sanitized_url;
}

int main() {
    char raw_url[256], *sanitized_url;

    printf("Enter raw URL: ");
    scanf("%s", raw_url);

    sanitized_url = sanitize_url(raw_url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    
    return 0;
}