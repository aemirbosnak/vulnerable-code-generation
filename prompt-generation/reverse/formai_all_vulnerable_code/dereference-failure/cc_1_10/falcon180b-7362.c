//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char* url) {
    int i, j;
    char *temp_url = malloc(MAX_URL_LENGTH);
    if (temp_url == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Copy the original URL to a temporary buffer
    strcpy(temp_url, url);

    // Remove leading/trailing whitespaces
    i = 0;
    while (isspace(temp_url[i])) {
        i++;
    }
    j = strlen(temp_url) - 1;
    while (isspace(temp_url[j])) {
        j--;
        temp_url[j] = '\0';
    }

    // Remove any invalid characters
    for (i = 0; i < j; i++) {
        if (!isalnum(temp_url[i]) && temp_url[i]!= '.' && temp_url[i]!= '-' && temp_url[i]!= '_') {
            temp_url[i] = '_';
        }
    }

    // Copy the sanitized URL back to the original buffer
    strcpy(url, temp_url);

    // Free the temporary buffer
    free(temp_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    // Get the URL from the user
    printf("Enter the URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}