//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sanitizeUrl(char *url) {
    char *sanitizedUrl = (char*)malloc(strlen(url)+1); // allocate memory for the sanitized URL

    int i = 0, j = 0, flag = 0;

    for(i=0; i<strlen(url); i++) {

        if(url[i] == ' ') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '0';
            j += 3;
        }
        else if(url[i] == '\'') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '7';
            j += 3;
        }
        else if(url[i] == '\"') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '2';
            j += 3;
        }
        else if(url[i] == '<') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '3';
            sanitizedUrl[j+2] = 'C';
            j += 3;
        }
        else if(url[i] == '>') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '3';
            sanitizedUrl[j+2] = 'E';
            j += 3;
        }
        else if(url[i] == '(') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '8';
            j += 3;
        }
        else if(url[i] == ')') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '9';
            j += 3;
        }
        else if(url[i] == '&') {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = '2';
            sanitizedUrl[j+2] = '6';
            j += 3;
        }
        else if(url[i] == '/') {
            flag++;
            if(flag >= 2) { // avoid double slashes
                continue;
            }
            else {
                sanitizedUrl[j] = url[i];
                j++;
            }
        }
        else {
            sanitizedUrl[j] = url[i];
            j++;
        }

    }

    sanitizedUrl[j] = '\0'; // add null terminator

    return sanitizedUrl; // return sanitized URL
}

int main(int argc, char *argv[]) {
    char *url = argv[1];
    char *sanitizedUrl = sanitizeUrl(url);

    printf("Original URL: %s\nSanitized URL: %s\n", url, sanitizedUrl);

    free(sanitizedUrl); // free allocated memory

    return 0;
}