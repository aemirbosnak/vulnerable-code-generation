//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048

int isValidChar(char c) {
    if (isalnum(c) || c == '-') {
        return 1;
    }
    return 0;
}

int isValidScheme(char *scheme) {
    if (strcmp(scheme, "http") == 0 || strcmp(scheme, "https") == 0) {
        return 1;
    }
    return 0;
}

int isValidHost(char *host) {
    int i;
    for (i = 0; i < strlen(host); i++) {
        if (!isalnum(host[i]) && host[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

int isValidURL(char *url) {
    char *scheme = strtok(url, "://");
    char *host = strtok(NULL, "/");
    int schemeLen = strlen(scheme);
    int hostLen = strlen(host);
    if (!isValidScheme(scheme) || schemeLen <= 0 ||!isValidHost(host) || hostLen <= 0) {
        return 0;
    }
    return 1;
}

char *sanitizeURL(char *url) {
    char *sanitizedUrl = malloc(MAX_URL_LENGTH * sizeof(char));
    int i = 0;
    for (i = 0; i < strlen(url); i++) {
        if (isValidChar(url[i])) {
            sanitizedUrl[i] = url[i];
        } else {
            sanitizedUrl[i] = '%';
            i++;
            sprintf(&sanitizedUrl[i], "%02X", (unsigned char)url[i]);
        }
    }
    sanitizedUrl[i] = '\0';
    return sanitizedUrl;
}

int main() {
    char input[MAX_URL_LENGTH];
    char *sanitizedInput;
    printf("Enter a URL to sanitize: ");
    fgets(input, MAX_URL_LENGTH, stdin);
    sanitizedInput = sanitizeURL(input);
    printf("Sanitized URL: %s\n", sanitizedInput);
    free(sanitizedInput);
    return 0;
}