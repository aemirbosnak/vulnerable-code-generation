//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 100    // maximum size of URL
#define MAX_DOMAIN_LENGTH 50  // maximum size of domain name

char *sanitize_url(char *url);

int main(void) {
    char url[MAX_URL_LENGTH];   // variable to store user input
    
    printf("Please enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);  // read user input
    
    char *sanitized_url = sanitize_url(url);   // sanitize the URL
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url);    // free dynamically allocated memory
    
    return 0;
}

// sanitize the input URL
char *sanitize_url(char *url) {
    // dynamically allocate memory for the sanitized URL
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    
    // remove leading and trailing whitespaces from input URL
    int i = 0;
    while (isspace(url[i])) {
        i++;    // move to next character if current character is whitespace
    }
    
    int j = strlen(url) - 1;
    while (isspace(url[j])) {
        j--;    // move to previous character if current character is whitespace
    }
    
    // copy the non-whitespace characters into sanitized URL
    strncpy(sanitized_url, &url[i], j-i+1);
    sanitized_url[j-i+1] = '\0';    // terminate the string with null character
    
    // check if the input URL starts with "http://" or "https://"
    if (strncmp(sanitized_url, "http://", 7) == 0) {
        // if it starts with "http://", copy it into sanitized URL
        strncpy(sanitized_url, "http://", 7);
        i = 7;  // update index
    } else if (strncmp(sanitized_url, "https://", 8) == 0) {
        // if it starts with "https://", copy it into sanitized URL
        strncpy(sanitized_url, "https://", 8);
        i = 8;  // update index
    } else {
        // if it doesn't start with "http://" or "https://", add "http://" to the beginning of sanitized URL
        strncpy(sanitized_url, "http://", 7);
        i = 0;  // update index
    }
    
    // loop through the remaining characters of the input URL
    while (i <= strlen(url)) {
        // check for invalid characters in domain name
        if (!isalnum(url[i]) && url[i] != '.' && url[i] != '-') {
            printf("Invalid character detected: %c\n", url[i]);
            exit(EXIT_FAILURE);
        }
        
        // if current character is a dot, check for consecutive dots
        if (url[i] == '.' && url[i+1] == '.') {
            printf("Consecutive dots detected.\n");
            exit(EXIT_FAILURE);
        }
        
        // copy the character into sanitized URL
        strncat(sanitized_url, &url[i], 1);
        i++;    // move to the next character
    }
    
    // make sure the domain name is not longer than MAX_DOMAIN_LENGTH
    int k;
    for (k = 7; k < strlen(sanitized_url); k++) {
        if (sanitized_url[k] == '/') {   // stop at the first slash (after domain name)
            break;
        }
    }
    
    if (k-7 > MAX_DOMAIN_LENGTH) {  // limit domain name to MAX_DOMAIN_LENGTH characters
        printf("Domain name is too long.\n");
        exit(EXIT_FAILURE);
    }
    
    // add a trailing slash to the sanitized URL if there isn't one already
    if (sanitized_url[strlen(sanitized_url)-1] != '/') {
        strncat(sanitized_url, "/", 1);
    }
    
    return sanitized_url;   // return the sanitized URL
}