//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define maximum length of url
#define MAX_LENGTH 1000

//function to sanitize the url
char* sanitizeUrl(char* url) {

    //allocate memory for the new sanitized url
    char* newUrl = (char*)malloc(MAX_LENGTH * sizeof(char));

    //initialize index variable
    int newIndex = 0;

    //loop through the url character by character
    for(int i = 0; i < strlen(url); i++) {
        
        //check if the character is not whitespace
        if(!isspace(url[i])) {

            //check if the character is a valid alphanumeric character or "-"
            if(isalnum(url[i]) || url[i] == '-') {

                //convert uppercase characters to lowercase
                newUrl[newIndex++] = tolower(url[i]);
            }
        }
    }

    //terminate the string with a null character
    newUrl[newIndex] = '\0';

    //return the sanitized url
    return newUrl;
}

int main() {

    //initialize the url variable
    char url[MAX_LENGTH];

    //prompt the user to enter the url
    printf("Enter the URL: ");
    scanf("%[^\n]%*c", url);

    //sanitize the url
    char* sanitizedUrl = sanitizeUrl(url);

    //print the sanitized url
    printf("The sanitized URL is: %s\n", sanitizedUrl);

    //free the memory allocated to the sanitized url
    free(sanitizedUrl);

    return 0;
}