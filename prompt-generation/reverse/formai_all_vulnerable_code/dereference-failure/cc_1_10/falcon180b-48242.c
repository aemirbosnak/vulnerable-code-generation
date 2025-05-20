//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char buffer[MAX_URL_LENGTH];

    // Remove any leading/trailing whitespace
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[j])) {
        j--;
    }

    // Copy the URL to a buffer
    memcpy(buffer, url + i, j - i + 1);
    buffer[j - i + 1] = '\0';

    // Replace any non-ASCII characters with their percent-encoded equivalents
    for (i = 0; i < strlen(buffer); i++) {
        if (!isalnum(buffer[i]) && buffer[i]!= '.' && buffer[i]!= '-') {
            sprintf(&buffer[i], "%%%02X", buffer[i]);
        }
    }

    // Copy the sanitized URL back to the original buffer
    strcpy(url, buffer);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Prompt the user to enter a URL
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}