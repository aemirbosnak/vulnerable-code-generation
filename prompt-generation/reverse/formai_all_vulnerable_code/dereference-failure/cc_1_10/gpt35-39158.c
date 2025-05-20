//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to sanitize a given URL string
char* sanitizeURL(char* url) {
    
    // define a list of forbidden characters
    char* forbiddens = "./:<>&?=#";
    
    // allocate memory for the sanitized URL string
    char* sanitizedURL = (char*)malloc(strlen(url) + 1);
    
    // copy the original URL string to the sanitized URL string
    strcpy(sanitizedURL, url);
    
    // loop through each character of the URL string
    for(int i = 0; i < strlen(sanitizedURL); i++) {
        
        // if the character is a forbidden character
        if(strchr(forbiddens, sanitizedURL[i]) != NULL) {
            
            // replace the character with an underscore
            sanitizedURL[i] = '_';
        }
        
        // if the character is a space
        if(sanitizedURL[i] == ' ') {
            
            // replace the space with a percent sign
            sanitizedURL[i] = '%';
            
            // move all following characters to make space for the percent-encoded sequence
            memmove(sanitizedURL + i + 3, sanitizedURL + i + 1, strlen(sanitizedURL + i + 1) + 1);
            
            // insert the percent-encoded sequence for a space character
            sanitizedURL[i+1] = '2';
            sanitizedURL[i+2] = '0';
            
            // update the loop index to reflect the insertion of two additional characters
            i += 2;
        }
        
        // if the character is a uppercase letter
        if(isupper(sanitizedURL[i])) {
            
            // convert the uppercase letter to its lowercase equivalent
            sanitizedURL[i] = tolower(sanitizedURL[i]);
        }
    }
    
    // return the sanitized URL string
    return sanitizedURL;
}

int main() {
    
    // prompt the user to enter a URL
    printf("Enter a URL to sanitize: ");
    
    // allocate memory for a string to store the user input
    char* userInput = (char*)malloc(1024);
    
    // read the user input
    fgets(userInput, 1024, stdin);
    
    // remove the new line character from the user input
    strtok(userInput, "\n");
    
    // sanitize the user input URL
    char* sanitizedURL = sanitizeURL(userInput);
    
    // print the sanitized URL
    printf("Sanitized URL: %s\n", sanitizedURL);
    
    // free allocated memory
    free(userInput);
    free(sanitizedURL);
    
    // return 0 to indicate successful program execution
    return 0;
}