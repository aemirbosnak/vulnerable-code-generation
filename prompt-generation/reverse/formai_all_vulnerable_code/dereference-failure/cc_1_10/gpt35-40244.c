//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

bool isCharSpecial(char c);
bool isStringValidURL(char* url);
char* sanitizeURL(char* url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL:\n");
    fgets(url, MAX_URL_LENGTH, stdin);

    if (isStringValidURL(url)) {
        printf("The URL is valid\n");
        char* sanitizedURL = sanitizeURL(url);
        printf("The sanitized URL is: %s\n", sanitizedURL);
        free(sanitizedURL);
    } else {
        printf("The URL is invalid\n");
    }

    return 0;
}

/* Determines if a character is special, i.e., not allowed in a URL */
bool isCharSpecial(char c) {
    switch (c) {
        case '!': case '#': case '$': case '&':
        case '\'': case '(': case ')': case '*':
        case '+': case ',': case '/': case ':':
        case ';': case '=': case '?': case '@':
        case '[': case ']': case '^': case '`':
        case '{': case '|': case '}': case '~':
            return true;
        default:
            return false;
    }
}

/* Determines if a string is a valid URL */
bool isStringValidURL(char* url) {
    int urlLength = strlen(url);
    if (urlLength < 7) { // must be at least "http://"
        return false;
    } else if (strncmp(url, "http://", 7) != 0) {
        return false;
    }
    for (int i = 7; i < urlLength; i++) {
        if (!(isalnum(url[i]) || isCharSpecial(url[i]))) {
            return false;
        }
    }
    return true;
}

/* Sanitizes a URL by replacing spaces with %20 and removing invalid characters */
char* sanitizeURL(char* url) {
    int urlLength = strlen(url);
    char* sanitizedURL = malloc(sizeof(char) * (urlLength + 1));
    int sanitizedURLIndex = 0;
    for (int i = 0; i < urlLength; i++) {
        if (url[i] == ' ') {
            sanitizedURL[sanitizedURLIndex++] = '%';
            sanitizedURL[sanitizedURLIndex++] = '2';
            sanitizedURL[sanitizedURLIndex++] = '0';
        } else if (isalnum(url[i]) || isCharSpecial(url[i])) {
            sanitizedURL[sanitizedURLIndex++] = url[i];
        }
    }
    sanitizedURL[sanitizedURLIndex] = '\0';
    return sanitizedURL;
}