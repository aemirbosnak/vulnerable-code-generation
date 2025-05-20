//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 1000

// This function sanitizes given URL and returns sanitized URL.
char* sanitizeUrl(char* url) {
    // output string to store sanitized URL
    char* sanitizedUrl = (char*) malloc(MAX_OUTPUT_SIZE);

    // iterate through each character of given URL
    int i, j;
    for(i = 0, j = 0; url[i]; i++) {
        // if current character is not alphanumeric or slash, skip it
        if(!isalnum(url[i]) && url[i] != '/') {
            continue;
        }

        // if current character is slash and next character is also slash, skip it
        if(url[i] == '/' && url[i+1] == '/') {
            i++;
            continue;
        }

        // append current character to sanitized URL
        sanitizedUrl[j++] = url[i];
    }

    // terminate sanitized URL with null character and return it
    sanitizedUrl[j] = '\0';
    return sanitizedUrl;
}

int main() {
    // input string to store URL input by user
    char* input = (char*) malloc(MAX_INPUT_SIZE);

    // get URL input from user
    printf("Enter URL to sanitize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // remove newline character from input string
    int len = strlen(input);
    if(input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // sanitize given URL
    char* sanitizedUrl = sanitizeUrl(input);

    // print sanitized URL
    printf("Sanitized URL: %s\n", sanitizedUrl);

    // free memory allocated to input and sanitizedUrl strings
    free(input);
    free(sanitizedUrl);
    return 0;
}