//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

// A function to check if a character is a valid URL character
bool isUrlChar(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
            || c == '/' || c == ':' || c == '.' || c == '-');
}

// A function to sanitize a URL
char* sanitizeUrl(char* url) {

    int n = strlen(url);

    // Allocate memory for the sanitized URL
    char* sanitizedUrl = (char*)malloc((MAX_URL_LENGTH + 1) * sizeof(char));

    // Initialize the sanitized URL with null characters
    memset(sanitizedUrl, '\0', MAX_URL_LENGTH + 1);

    // Initialize a counter for the sanitized URL
    int sanitizedUrlCounter = 0;

    // Iterate through each character of the URL
    for (int i = 0; i < n; i++) {

        // Check if the character is a valid URL character
        if (isUrlChar(url[i])) {
            sanitizedUrl[sanitizedUrlCounter++] = url[i];
        }
        // If the character is a whitespace, replace it with %20
        else if (url[i] == ' ') {
            strcat(sanitizedUrl, "%20");
            sanitizedUrlCounter += 3;
        }
        // Otherwise, skip the character
    }

    return sanitizedUrl;
}

// Main function to test the URL sanitizer
int main() {

    // Sample URLs for testing
    char url1[] = "https://en.wikipedia.org/wiki/C_(programming_language)#External_links";
    char url2[] = "https://www.google.com/search?q=c+programming&oq=c+programming";
    char url3[] = "https://www.youtube.com/watch?v=KJgsSFOSQv0";

    // Sanitize the URLs
    char* sanitizedUrl1 = sanitizeUrl(url1);
    char* sanitizedUrl2 = sanitizeUrl(url2);
    char* sanitizedUrl3 = sanitizeUrl(url3);

    // Print the sanitized URLs
    printf("Sanitized URL 1: %s\n", sanitizedUrl1);
    printf("Sanitized URL 2: %s\n", sanitizedUrl2);
    printf("Sanitized URL 3: %s\n", sanitizedUrl3);

    // Free the memory allocated for the sanitized URLs
    free(sanitizedUrl1);
    free(sanitizedUrl2);
    free(sanitizedUrl3);

    return 0;
}