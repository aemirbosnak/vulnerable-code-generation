//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100 // Maximum allowed length for a URL

// Function to sanitize a given URL
void sanitizeURL(char *url) {
    // Remove any whitespace characters from the beginning of the URL
    while (*url == ' ') {
        url++;
    }
    
    // Remove any whitespace characters from the end of the URL
    int len = strlen(url);
    while (len > 0 && url[len - 1] == ' ') {
        len--;
    }
    url[len] = '\0';
    
    // Check if the URL starts with 'http://' or 'https://'
    char *start = strstr(url, "http://");
    if (start == NULL) {
        start = strstr(url, "https://");
    }
    
    // If the URL does not start with 'http://' or 'https://', add 'http://'
    if (start == NULL || start != url) {
        char *temp = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);
        strcpy(temp, "http://");
        strcat(temp, url);
        strncpy(url, temp, MAX_URL_LENGTH);
        free(temp);
    }
    
    // Remove any fragment identifiers from the URL
    char *fragment = strchr(url, '#');
    if (fragment != NULL) {
        *fragment = '\0';
    }
    
    // Remove any query parameters from the URL
    char *params = strchr(url, '?');
    if (params != NULL) {
        *params = '\0';
    }
    
    // Convert any non-alphanumeric characters in the URL to %XX format
    int i = 0;
    while (url[i] != '\0') {
        if (!isalnum(url[i])) {
            char temp[4];
            sprintf(temp, "%%%02x", url[i]);
            memmove(&url[i + 3], &url[i + 1], strlen(&url[i + 1]) + 1);
            memcpy(&url[i], temp, 3);
            i += 3;
        }
        i++;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    
    sanitizeURL(url);
    printf("The sanitized URL is: %s\n", url);
    
    return 0;
}