//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 2048

int isValidChar(char c) {
    if (isalpha(c) || isdigit(c) || c == '.' || c == '-' || c == '_' || c == '~' || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$' || c == ',' || c == '/' || c == '?' || c == '%') {
        return 1;
    } else {
        return 0;
    }
}

int isValidUrl(char *url) {
    int i = 0;
    while (url[i]!= '\0') {
        if (!isValidChar(url[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *sanitizeUrl(char *url) {
    int i = 0;
    char *sanitizedUrl = malloc(MAX_LENGTH * sizeof(char));
    while (url[i]!= '\0') {
        if (isValidChar(url[i])) {
            sanitizedUrl[i] = url[i];
        } else {
            sanitizedUrl[i] = '%';
            i++;
            sprintf(&sanitizedUrl[i], "%02X", (int)url[i]);
        }
        i++;
    }
    sanitizedUrl[i] = '\0';
    return sanitizedUrl;
}

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    char *sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);
    return 0;
}