//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize the URL
char *sanitize(char *url) {
    // Convert the URL to lowercase
    for (int i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any extra whitespace
    char *temp = (char *)malloc(strlen(url) + 1);
    int j = 0;
    int space_count = 0;
    for (int i = 0; url[i]; i++) {
        if (isspace(url[i])) {
            space_count++;
        } else {
            space_count = 0;
        }

        // Skip consecutive spaces
        if (space_count <= 1) {
            temp[j] = url[i];
            j++;
        }
    }
    temp[j] = '\0';
    free(url);
    url = temp;

    // Remove any trailing slashes
    if (url[strlen(url) - 1] == '/') {
        url[strlen(url) - 1] = '\0';
    }

    // Remove any "http://" or "https://" prefixes
    if (strncmp(url, "http://", 7) == 0) {
        memmove(url, url + 7, strlen(url) - 6);
    }
    if (strncmp(url, "https://", 8) == 0) {
        memmove(url, url + 8, strlen(url) - 7);
    }

    // Replace any "www." with ""
    if (strncmp(url, "www.", 4) == 0) {
        memmove(url, url + 4, strlen(url) - 3);
    }

    // Replace any "#" with ""
    if (strchr(url, '#') != NULL) {
        char *hash = strchr(url, '#');
        *hash = '\0';
    }

    // Check that the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        char *new_url = (char *)malloc(strlen(url) + 8);
        strcpy(new_url, "http://");
        strcat(new_url, url);
        free(url);
        url = new_url;
    }

    return url;
}

int main() {
    // Get input URL from user
    char url[1000];
    printf("Enter a URL to sanitize:\n");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';

    // Sanitize the URL
    char *sanitized_url = sanitize(url);

    // Print the sanitized URL
    printf("Sanitized URL:\n%s\n", sanitized_url);

    // Free memory
    free(sanitized_url);

    return 0;
}