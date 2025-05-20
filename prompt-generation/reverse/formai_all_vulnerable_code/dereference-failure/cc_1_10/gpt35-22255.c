//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to sanitize a URL
void sanitize_url(char *url) {

    // Remove any spaces at the beginning of the URL
    int i = 0;
    while (url[i] == ' ') {
        i++;
    }
    if (i != 0) {
        strcpy(url, &url[i]);
    }

    // Remove any spaces at the end of the URL
    i = strlen(url) - 1;
    while (url[i] == ' ') {
        url[i] = '\0';
        i--;
    }

    // Remove any leading or trailing slashes
    if (url[0] == '/') {
        strcpy(url, &url[1]);
    }
    i = strlen(url) - 1;
    if (i >= 0 && url[i] == '/') {
        url[i] = '\0';
    }

    // Remove any double slashes
    i = 0;
    while (url[i] != '\0') {
        if (url[i] == '/' && url[i+1] == '/') {
            strcpy(&url[i], &url[i+1]);
        }
        else {
            i++;
        }
    }

    // Ensure the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7)!=0 && strncmp(url, "https://", 8)!=0) {
        strcpy(url, "http://");
        strcat(url, url);
    }
}

int main() {
    char url[1000];
    printf("Enter a URL: ");
    fgets(url, 1000, stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s", url);
    return 0;
}