//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove leading/trailing spaces
    char *trimmed_url = url;
    while (isspace(*trimmed_url)) {
        trimmed_url++;
    }
    int len = strlen(trimmed_url);
    while (isspace(trimmed_url[len - 1])) {
        trimmed_url[--len] = '\0';
    }

    // Check if URL is valid
    if (isValidURL(trimmed_url)) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}

int isValidURL(char *url) {
    int len = strlen(url);
    if (len < 7 || len > MAX_URL_LENGTH) {
        return 0;
    }

    char *protocol = url;
    while (*protocol!= ':') {
        protocol++;
    }
    if (protocol - url > 6) {
        return 0;
    }

    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8)) {
        return 0;
    }

    char *host = protocol + 3;
    while (*host!= '/') {
        host++;
    }

    while (*host!= 0) {
        if (!isalnum(*host) && *host!= '-') {
            return 0;
        }
        host++;
    }

    return 1;
}