//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_URL_LENGTH 2048

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int j = 0;
    int k = 0;
    int is_valid_char = 0;

    while (url[i]) {
        if (isalpha(url[i]) || isdigit(url[i]) || url[i] == '-') {
            is_valid_char = 1;
        } else if (url[i] == '.') {
            if (i > 0 && i < MAX_URL_LENGTH - 1 && is_valid_char) {
                sanitized_url[j++] = url[i];
            }
            is_valid_char = 0;
        } else if (url[i] == '/' && k == 0) {
            if (i > 0 && i < MAX_URL_LENGTH - 1 && is_valid_char) {
                sanitized_url[j++] = url[i];
            }
            is_valid_char = 0;
            k++;
        } else if (url[i] == '/' && k > 0) {
            if (i > 0 && i < MAX_URL_LENGTH - 1 && is_valid_char) {
                sanitized_url[j++] = url[i];
            }
            is_valid_char = 0;
            k--;
        }
        i++;
    }

    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char *url = "https://example.com/path/to/page?query=string#fragment";
    char *sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}