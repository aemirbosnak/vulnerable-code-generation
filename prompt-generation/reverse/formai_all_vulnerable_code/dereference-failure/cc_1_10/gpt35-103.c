//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

// Function to check if a character is alpha-numeric or not
int isAlphaNumeric(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to sanitize a given URL
void sanitizeURL(char* url) {
    int i, j;
    char* sanitizedUrl = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);

    // Removing extra whitespace characters from the URL
    for (i = 0, j = 0; i < strlen(url); i++) {
        if (!isspace(url[i])) {
            sanitizedUrl[j++] = url[i];
        }
    }

    sanitizedUrl[j] = '\0';

    // Converting the URL to lowercase
    for (i = 0; i < strlen(sanitizedUrl); i++) {
        sanitizedUrl[i] = tolower(sanitizedUrl[i]);
    }

    // Removing any trailing forward slashes from the URL
    if (sanitizedUrl[strlen(sanitizedUrl)-1] == '/') {
        sanitizedUrl[strlen(sanitizedUrl)-1] = '\0';
    }

    // Removing any unneeded characters from the URL
    for (i = 0, j = 0; i < strlen(sanitizedUrl); i++) {
        if (isAlphaNumeric(sanitizedUrl[i]) || sanitizedUrl[i] == '/' || sanitizedUrl[i] == '.' || sanitizedUrl[i] == '-') {
            sanitizedUrl[j++] = sanitizedUrl[i];
        }
    }

    sanitizedUrl[j] = '\0';

    // Copying the sanitized URL back to the original URL variable
    strcpy(url, sanitizedUrl);

    free(sanitizedUrl);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter the URL to be sanitized: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    sanitizeURL(url);
    printf("The sanitized URL is: %s\n", url);

    return 0;
}