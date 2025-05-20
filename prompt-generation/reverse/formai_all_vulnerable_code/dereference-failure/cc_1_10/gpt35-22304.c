//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
// function to sanitize a URL
char* sanitizeUrl(char* url) {
    int i, j = 0, len = strlen(url);
    char* sanitizedUrl = calloc(len+1, sizeof(char));
     
    // loop through each character in the URL
    for(i=0; i < len; i++) {
        switch(url[i]) {
            case '\'':
            case '\"':
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
            case '<':
            case '>':
            case '`':
            case '|':
            case '\\':
            case '^':
                // replace illegal characters with '-'
                sanitizedUrl[j++] = '-';
                break;
            case ' ':
                // replace spaces with '-'
                sanitizedUrl[j++] = '-';
                break;
            default:
                // check if the char is alphanumeric or a hyphen, if so add to sanitized URL
                if(isalnum(url[i]) || url[i] == '-') {
                    sanitizedUrl[j++] = url[i];
                }
                else {
                    // if not alphanumeric or hyphen, replace with '_'
                    sanitizedUrl[j++] = '_';
                }
                break;
        }
    }
    // append null terminator to sanitized URL string
    sanitizedUrl[j] = '\0';
    return sanitizedUrl;
}
 
int main() {
    char url[1024];
 
    printf("Enter a URL to sanitize: ");
    fgets(url, 1024, stdin);
    
    // remove newline character from end of URL string
    url[strcspn(url, "\n")] = 0;
 
    // sanitize URL
    char* sanitizedUrl = sanitizeUrl(url);
 
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedUrl);
 
    free(sanitizedUrl);
 
    return 0;
}