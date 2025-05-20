//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
/**
* A visionary URL sanitizer program written in C.
* This program takes in a URL input, sanitizes it by removing any malicious characters, and returns a safe URL.
* 
* Author: Your Name
* Date: Current Date
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2000

char *sanitizeUrl(char *url);

int main(void) {
    char inputUrl[MAX_URL_LENGTH];
    char *sanitizedUrl;

    printf("Enter a URL to sanitize: ");
    fgets(inputUrl, MAX_URL_LENGTH, stdin);

    sanitizedUrl = sanitizeUrl(inputUrl);

    printf("\nSanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl); // free allocated memory

    return 0;
}

char *sanitizeUrl(char *url) {
    char *sanitizedUrl;
    int i, j, urlLength;

    urlLength = strlen(url);

    sanitizedUrl = (char *) malloc(urlLength + 1); // allocate memory for sanitized URL

    j = 0;
    for (i = 0; i < urlLength; i++) {
        if ((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') || (url[i] >= '0' && url[i] <= '9')
            || url[i] == ':' || url[i] == '/' || url[i] == '.' || url[i] == '-' || url[i] == '_') {
            sanitizedUrl[j] = url[i];
            j++;
        }
    }

    sanitizedUrl[j] = '\0'; // add null character to end of sanitized URL

    return sanitizedUrl;
}