//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize a given URL
void sanitize_URL(char *URL) {
    // Remove all spaces from the URL
    char *temp_URL = URL, *sanitized_URL = URL;
    while (*temp_URL) {
        if (*temp_URL != ' ')
            *sanitized_URL++ = *temp_URL;
        temp_URL++;
    }
    *sanitized_URL = '\0';
    
    // Convert the URL to lowercase
    temp_URL = sanitized_URL = URL;
    while (*temp_URL) {
        *sanitized_URL = tolower(*temp_URL);
        sanitized_URL++;
        temp_URL++;
    }
    *sanitized_URL = '\0';
    
    // Check if the URL is of valid format, if not fix it
    if (strncmp(URL, "http://", 7) != 0 && strncmp(URL, "https://", 8) != 0) {
        char* fixed_URL = malloc(sizeof(char) * (strlen(URL) + 8));
        strcpy(fixed_URL, "http://");
        strcat(fixed_URL, URL);
        strcpy(URL, fixed_URL);
        free(fixed_URL);
    }
    
    // Check if the URL ends with '/'
    int URL_length = strlen(URL);
    if (URL[URL_length - 1] != '/') {
        char* fixed_URL = malloc(sizeof(char) * (URL_length + 2));
        strcpy(fixed_URL, URL);
        strcat(fixed_URL, "/");
        strcpy(URL, fixed_URL);
        free(fixed_URL);
    }
}

int main() {
    // Testing of the sanitizer function
    char URL[100] = "Www.Example.com/path with spaces/Page.html ";
    printf("Before sanitization: %s\n", URL);
    
    sanitize_URL(URL);
    printf("After sanitization: %s\n", URL);
    
    return 0;
}