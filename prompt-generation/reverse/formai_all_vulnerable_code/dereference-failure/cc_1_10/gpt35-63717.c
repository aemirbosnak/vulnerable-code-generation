//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

char* sanitizeUrl(char* url) {
    char* sanitizedUrl = malloc(MAX_URL_LENGTH);
    int i = 0, j = 0;

    while(url[i] != '\0') {

        if(isspace(url[i])) { // Replace spaces with %20
            sanitizedUrl[j++] = '%';
            sanitizedUrl[j++] = '2';
            sanitizedUrl[j++] = '0';
        }

        else if(isalnum(url[i])) { // If alphanumeric, simply append to sanitized URL
            sanitizedUrl[j++] = url[i];
        }

        else if(url[i] == ':' && url[i+1] == '/' && url[i+2] == '/') { // If :// encountered, simply append to sanitized URL
            sanitizedUrl[j++] = url[i];
            sanitizedUrl[j++] = url[i+1];
            sanitizedUrl[j++] = url[i+2];
            i += 2;
        }

        i++;
    }

    sanitizedUrl[j] = '\0'; // Terminate the sanitized URL

    return sanitizedUrl; // Return the sanitized URL
}

int main() {
    char url[MAX_URL_LENGTH], *sanitizedUrl;

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitizedUrl = sanitizeUrl(url);

    printf("\nSanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl); // Free the allocated memory

    return 0;
}