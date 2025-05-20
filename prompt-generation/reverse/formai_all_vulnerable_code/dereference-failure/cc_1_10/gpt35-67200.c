//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    memset(sanitized_url, 0, MAX_URL_LENGTH);
    
    for(i = 0, j = 0; url[i]; i++, j++) {
        if(isspace(url[i])) {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '0';
            j += 2;
        }
        else if(url[i] == '<') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '3';
            sanitized_url[j+2] = 'C';
            j += 2;
        }
        else if(url[i] == '>') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '3';
            sanitized_url[j+2] = 'E';
            j += 2;
        }
        else if(url[i] == '\"') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '2';
            j += 2;
        }
        else if(url[i] == '\'') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '7';
            j += 2;
        }
        else if(url[i] == '(') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '8';
            j += 2;
        }
        else if(url[i] == ')') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '9';
            j += 2;
        }
        else if(url[i] == '&') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '6';
            j += 2;
        }
        else if(url[i] == '#') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '3';
            j += 2;
        }
        else {
            sanitized_url[j] = url[i];
        }
    }
    
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;
    
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    
    return 0;
}