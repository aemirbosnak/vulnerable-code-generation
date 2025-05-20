//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
This program implements a URL sanitizer, which checks user-provided URLs for
illegal characters and removes them. The sanitized URL can then be safely used by
other programs. In this implementation, only the basic Latin alphabet is allowed, 
along with digits and certain common symbols.
*/

// Define the maximum length of a URL
#define MAX_URL_LEN 1000

// Define a function to check if a char is a valid URL character
int is_valid_char(char c) {
    if (isalpha(c)) {
        return 1; // character is a letter
    } else if (isdigit(c)) {
        return 1; // character is a digit
    } else {
        // check if character is one of the allowed symbols
        switch(c) {
            case ':':
            case '@':
            case '/':
            case '-':
            case '.':
            case '_':
                return 1;
            default:
                return 0;
        }
    }
}

// Define a function to sanitize a URL
char* sanitize_url(char* url) {
    int len = strlen(url);
    char* sanitized_url = (char*) malloc((MAX_URL_LEN + 1) * sizeof(char));
    
    // loop through each character in the URL
    int i;
    for (i = 0; i < len; i++) {
        char c = url[i];
        if (is_valid_char(c)) {
            sanitized_url[i] = c; // valid character, copy to new URL
        } else {
            // invalid character, do not copy to new URL
            sanitized_url[i] = '\0';
        }
    }
    sanitized_url[i] = '\0'; // add null terminator to end of new URL
    
    return sanitized_url;
}

// Define a function to test the URL sanitizer
void test_url_sanitizer() {
    char* url1 = "http://www.example.com";
    char* url2 = "https://www.my-site.com/my-page?param1=123&param2=abc";
    char* url3 = "ftp://user:pass@ftp.server.com";
    
    char* sanitized_url1 = sanitize_url(url1);
    char* sanitized_url2 = sanitize_url(url2);
    char* sanitized_url3 = sanitize_url(url3);
    
    printf("Original URL: %s\n", url1);
    printf("Sanitized URL: %s\n", sanitized_url1);
    printf("\n");
    printf("Original URL: %s\n", url2);
    printf("Sanitized URL: %s\n", sanitized_url2);
    printf("\n");
    printf("Original URL: %s\n", url3);
    printf("Sanitized URL: %s\n", sanitized_url3);
    
    free(sanitized_url1);
    free(sanitized_url2);
    free(sanitized_url3);
}

// Define the main function
int main() {
    test_url_sanitizer();
    return 0;
}