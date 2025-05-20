//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url) {
    int i = 0, j = 0, k = 0;
    char *sanitized_url = malloc(MAX_URL_LENGTH);

    while (url[i]) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '~' || url[i] == '/' || url[i] == '?'|| url[i] == '&' || url[i] == '=' || url[i] == '+' || url[i] == '%') {
            sanitized_url[j] = url[i];
            j++;
        } else if (url[i] == '%') {
            i++;
            if (isxdigit(url[i]) && isxdigit(url[i+1])) {
                sanitized_url[j] = '%';
                j++;
                sanitized_url[j] = url[i];
                j++;
                sanitized_url[j] = url[i+1];
                j++;
                i += 2;
            } else {
                sanitized_url[j] = '%25';
                j++;
            }
        } else {
            sanitized_url[j] = '%';
            j++;
            sprintf(&sanitized_url[j], "%02X", url[i]);
            j += 3;
        }
        i++;
    }

    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char *url = "https://example.com/path/to/resource?foo=bar&baz=qux#frag";
    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}