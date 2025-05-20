//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* surreal_c_url_sanitizer(char* url) {
    char* sanitized_url = (char*) malloc(strlen(url) + 1);
    int i, j = 0, count = 0;
    int len = strlen(url);

    for (i = 0; i < len; i++) {
        if (url[i] == 'j' && url[i+1] == 'u' && url[i+2] == 'n' && url[i+3] == 'g' && url[i+4] == 'l' && url[i+5] == 'e') {
            count++;
            sanitized_url[j++] = 'f';
            sanitized_url[j++] = 'o';
            sanitized_url[j++] = 'r';
            sanitized_url[j++] = 'e';
            sanitized_url[j++] = 's';
            sanitized_url[j++] = 't';
        } else if (url[i] == ':' && url[i+1] == '/' && url[i+2] == '/') {
            sanitized_url[j++] = ':';
            sanitized_url[j++] = '/';
            sanitized_url[j++] = '/';
            i += 2;
        } else if (url[i] == 'w' && url[i+1] == 'w' && url[i+2] == 'w' && url[i+3] == '.') {
            count++;
            if (count % 2 == 0) {
                sanitized_url[j++] = 'w';
                sanitized_url[j++] = 'o';
                sanitized_url[j++] = 'n';
                sanitized_url[j++] = 'd';
                sanitized_url[j++] = 'e';
                sanitized_url[j++] = 'r';
            } else {
                sanitized_url[j++] = 'o';
                sanitized_url[j++] = 'w';
                sanitized_url[j++] = 'l';
            }
            i += 3;
        } else if (url[i] == '.') {
            sanitized_url[j++] = url[i];
            i++;
        } else {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[100] = "http://www.jumpjungle.com";
    char* sanitized_url = surreal_c_url_sanitizer(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);

    char url2[300] = "https://www.google.com/search?q=python+automate+browser";
    char* sanitized_url2 = surreal_c_url_sanitizer(url2);
    printf("Original URL: %s\n", url2);
    printf("Sanitized URL: %s\n", sanitized_url2);
    free(sanitized_url2);

    return 0;
}