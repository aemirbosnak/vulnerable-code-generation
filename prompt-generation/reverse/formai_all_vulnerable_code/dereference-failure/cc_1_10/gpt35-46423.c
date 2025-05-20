//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The function that will sanitize the URL
char* sanitizeURL(char* url) {
    int i, j, len;
    len = strlen(url);

    // Let's create a new URL string to store the sanitized URL
    char* newURL = (char*) malloc(sizeof(char)*(len+1));
    j = 0;

    // We will go through every character of the input URL
    for(i=0; i<len; i++) {
        // If the character is a letter, we will just copy it to the new URL
        if(isalpha(url[i])) {
            newURL[j] = tolower(url[i]);
            j++;
        }
        // If the character is a digit, we will also copy it
        else if(isdigit(url[i])) {
            newURL[j] = url[i];
            j++;
        }
        // If the character is a hyphen or a period, we will also copy it
        else if(url[i] == '-' || url[i] == '.') {
            newURL[j] = url[i];
            j++;
        }
        // If the character is anything else, we will skip it
    }

    // We need to add the null terminator to the new URL string
    newURL[j] = '\0';

    // Return the sanitized URL
    return newURL;
}

// The main function that will test the sanitizeURL function
int main() {
    char url[100];
    printf("Greetings, traveler! Enter thine URL which thou wisheth to sanitize:\n");
    scanf("%s", url);

    // Sanitize the URL
    char* sanitizedURL = sanitizeURL(url);

    // Print the sanitized URL
    printf("Thine sanitized URL is:\n");
    printf("%s\n", sanitizedURL);

    // Free the memory allocated for the sanitized URL string
    free(sanitizedURL);

    printf("Farewell, traveler!\n");

    return 0;
}