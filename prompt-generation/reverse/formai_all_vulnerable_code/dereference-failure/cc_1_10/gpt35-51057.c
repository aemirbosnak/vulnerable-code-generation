//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

char* sanitize_url(char* url) {
    char* sanitized = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int i, j, length;
    j = 0;
    length = strlen(url);

    for(i = 0; i < length; i++) {
        char c = url[i];
        if(c == '"') {
            sanitized[j++] = '%';
            sanitized[j++] = '2';
            sanitized[j] = '2';
        }
        else if(c == '\'') {
            sanitized[j++] = '%';
            sanitized[j++] = '2';
            sanitized[j] = '7';
        }
        else if(c == ' ') {
            sanitized[j++] = '%';
            sanitized[j++] = '2';
            sanitized[j] = '0';
        }
        else if(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.' || c == '/') {
            sanitized[j] = c;
        }
        else {
            sanitized[j++] = '%';
            sprintf(&sanitized[j], "%02X", c);
            j += 2;
        }
        if(j > MAX_URL_LENGTH - 4) {
            fprintf(stderr, "Error - URL too long\n");
            exit(EXIT_FAILURE);
        }
        j++;
    }
    sanitized[j] = '\0';
    return sanitized;
}

int main() {
    char* url = "https://example.com/test?a=1&b=2&c=d#fragment";
    char* sanitized = sanitize_url(url);
    printf("Orginal URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}