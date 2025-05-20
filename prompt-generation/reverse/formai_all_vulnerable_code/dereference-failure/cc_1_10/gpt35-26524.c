//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 200
#define MAX_PARAM_LENGTH 50

// Check if the character is an allowed character in a URL
bool isAllowedChar(char c) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
        return true;
    }
    return false;
}

// Sanitize URL function
char* sanitizeURL(char* url) {
    int len = strlen(url);
    char* newURL = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int newIndex = 0;
    bool paramFound = false;

    // Loop through each character in the original URL
    for (int i = 0; i < len; i++) {
        char c = url[i];

        // If a parameter is found, set the paramFound flag to true
        if (c == '?') {
            paramFound = true;
        }

        // If the current character is not an allowed character,
        // replace it with its corresponding hex value
        if (!isAllowedChar(c)) {
            char hex[3];
            sprintf(hex, "%02X", c);

            // If a parameter has been found and the current character is
            // a space, replace it with a plus sign
            if (c == ' ' && paramFound) {
                newURL[newIndex++] = '+';
            } else {
                newURL[newIndex++] = '%';
            }

            newURL[newIndex++] = hex[0];
            newURL[newIndex++] = hex[1];
        } else {
            newURL[newIndex++] = c;
        }

        // If a parameter has been found, check if we have reached the
        // maximum parameter length. If yes, break the loop
        if (paramFound && newIndex >= MAX_URL_LENGTH - MAX_PARAM_LENGTH) {
            break;
        }
    }

    newURL[newIndex] = '\0'; // Add null terminator to the end of the string

    // Return the sanitized URL
    return newURL;
}

int main() {
    char* url = "https://www.example.com/some page?param1=value1&param2=value2 with spaces";
    char* sanitizedURL = sanitizeURL(url);

    printf("Original URL:   %s\n", url);
    printf("Sanitized URL:  %s\n", sanitizedURL);

    free(sanitizedURL); // Free dynamically allocated memory

    return 0;
}