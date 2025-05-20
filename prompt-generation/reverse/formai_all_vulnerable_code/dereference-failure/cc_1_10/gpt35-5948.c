//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if the character is a valid URL character
int isValidURLChar(char c) {
    return isalnum(c) || c == '.' || c == '-' || c == '_' || c == '~';
}

// Function to sanitize a URL string
char* sanitizeURL(char* url) {
    int len = strlen(url);
    char* newURL = (char*) malloc(sizeof(char) * (len + 1));
    int newIndex = 0;
    for (int i = 0; i < len; i++) {
        if (isValidURLChar(url[i])) {
            newURL[newIndex++] = url[i];
        } else if (url[i] == ' ') {
            newURL[newIndex++] = '+';
        } else {
            char hex[4];
            snprintf(hex, 4, "%%%02x", url[i]);
            newURL[newIndex++] = hex[0];
            newURL[newIndex++] = hex[1];
            newURL[newIndex++] = hex[2];
        }
    }
    newURL[newIndex] = '\0';
    return newURL;
}

int main() {
    char url1[] = "http://www.google.com/search?q=c programming";
    char url2[] = "ftp://user@server.com/path?query=string";
    char url3[] = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";

    char* sanitizedURL1 = sanitizeURL(url1);
    char* sanitizedURL2 = sanitizeURL(url2);
    char* sanitizedURL3 = sanitizeURL(url3);

    printf("[Original URL]: %s\n[Sanitized URL]: %s\n\n", url1, sanitizedURL1);
    printf("[Original URL]: %s\n[Sanitized URL]: %s\n\n", url2, sanitizedURL2);
    printf("[Original URL]: %s\n[Sanitized URL]: %s\n\n", url3, sanitizedURL3);

    free(sanitizedURL1);
    free(sanitizedURL2);
    free(sanitizedURL3);

    return 0;
}