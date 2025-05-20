//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
void sanitize_url(char *url) {
    int i, j;
    char *p;

    // Remove leading and trailing spaces
    while (isspace(*url)) {
        url++;
    }
    p = url + strlen(url) - 1;
    while (isspace(*p)) {
        p--;
        *p = '\0';
    }

    // Convert to lowercase
    for (i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    // Remove invalid characters
    for (i = 0, j = 0; url[i]; i++) {
        if (isalnum(url[i])) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get input URL from user
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}