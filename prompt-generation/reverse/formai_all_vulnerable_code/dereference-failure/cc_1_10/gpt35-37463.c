//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URLs
char* sanitizeURL(char* url) {
    // Declare variables
    char* sanitizedURL = malloc(strlen(url) + 1);
    char* temp = sanitizedURL;
    int index = 0;
    int length = strlen(url);
    
    // Loop through each character in the original URL
    for (int i = 0; i < length; i++) {
        char currentChar = url[i];
        
        // Check if current character is an alphabetical character or a digit
        if (isalnum(currentChar)) {
            *temp++ = currentChar;
            index++;
        }
        // Ignore all other characters
        else {
            index++;
        }
    }
    
    // Add a null terminator to the sanitized URL string
    *temp = '\0';
    
    return sanitizedURL;
}

int main() {
    // Declare variables
    char url[256];
    
    // Ask user to enter a URL to sanitize
    printf("Enter a URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    
    // Remove newline character from input
    url[strcspn(url, "\n")] = 0;
    
    // Sanitize the URL
    char* sanitizedURL = sanitizeURL(url);
    
    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitizedURL);
    
    // Free allocated memory
    free(sanitizedURL);
    
    return 0;
}