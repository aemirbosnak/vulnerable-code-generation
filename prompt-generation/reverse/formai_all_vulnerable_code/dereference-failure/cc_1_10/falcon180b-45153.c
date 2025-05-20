//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool isValidChar(char c) {
    if (isalpha(c) || isdigit(c) || c == '-') {
        return true;
    }
    switch (c) {
        case '.':
        case '_':
        case '+':
        case '~':
        case '*':
        case '/':
        case '?':
        case ':':
        case '&':
        case '=':
        case '%':
        case '$':
        case '#':
        case '@':
            return true;
        default:
            return false;
    }
}

void urlSanitize(char* url) {
    int i = 0, j = 0;
    char* sanitizedUrl = malloc(MAX_URL_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (isValidChar(url[i])) {
            sanitizedUrl[j++] = tolower(url[i]);
        }
        i++;
    }
    sanitizedUrl[j] = '\0';
    printf("Sanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    urlSanitize(url);
    return 0;
}