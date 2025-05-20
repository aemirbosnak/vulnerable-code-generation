//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 2048

void sanitizeUrl(char *url) {
    // Remove any trailing spaces
    if (url[strlen(url) - 1] == ' ') {
        url[strlen(url) - 1] = '\0';
    }

    // Remove any leading or trailing spaces from the query parameters
    char *query = strstr(url, "?");
    if (query != NULL) {
        query++;
        int queryLength = strlen(query);
        if (query[queryLength - 1] == ' ') {
            query[queryLength - 1] = '\0';
        }
        if (query[0] == ' ') {
            int i;
            for (i = 0; i < queryLength; i++) {
                query[i] = query[i + 1];
            }
        }
    }

    // Remove any trailing slashes
    int i;
    for (i = strlen(url) - 1; i >= 0; i--) {
        if (url[i] == '/') {
            url[i] = '\0';
        } else {
            break;
        }
    }

    // Remove any duplicate slashes
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == '/' && url[i + 1] == '/') {
            int j;
            for (j = i; url[j] != '\0'; j++) {
                url[j] = url[j + 1];
            }
            i--;
        }
    }

    // Remove any dots that don't change the meaning of the URL
    char *token = strtok(url, "/");
    char *prevToken = NULL;
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
            int tokenLength = strlen(token);
            int j;
            for (j = 0; j < tokenLength; j++) {
                token[j] = token[j + 1];
            }
        } else if (strcmp(token, "..") == 0) {
            if (prevToken != NULL) {
                *prevToken = '\0';
            }
        }
        prevToken = token;
        token = strtok(NULL, "/");
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    sanitizeUrl(url);
    printf("%s", url);
    return 0;
}